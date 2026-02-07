/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:28 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 23:12:18 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ft_libft.h"

int		valid_file(char *pathname, char *name);
int		get_idx_chr(char *str, char c);
int		split_path_dirs(char **envp, t_pipe_util *util);
int	cnt_input_cmds(int argc);
int		get_cmd_list(int argc, char	**argv, t_pipe_util *util);
char	*find_exec_path(t_pipe_util *arr, char *cmd);
int		create(t_pipe_util *util, t_fd *fd, char **argv, char **envp);
void	print_errno(char **argv, char *error_obj);
int	exec_child_p(int i, t_fd *fd, t_pipe_util *util, char **envp, char **argv);
int	test(t_pipe_util *path, t_fd *fd, char **envp, char **argv);
int	exec_last_cmd(int i, t_pipe_util *util, t_fd *fd, char **envp, char **argv);
int	exec_cmd(int i, t_pipe_util *util, t_fd *fd, char **envp, char **argv);
void	print_cur_exe_name(char **argv);
void	print_error_msg(char **argv, char *error_obj);
void	print_errno(char **argv, char *error_obj);

int	main(int argc, char **argv, char **envp)
{
	t_pipe_util	path;
	t_fd		fd;
	int			i;

	if (argc != 5)
		return (FAILURE);
	else
	{
		i = 0;
		if (!split_path_dirs(envp, &path))
			return (FAILURE); // path->dirs_path free 필요 (char **)
		if (!get_cmd_list(argc, argv, &path))
			return (FAILURE); // path->cmd_list free 필요 (char ***)
		create(&path, &fd, argv, envp);
	}
}

int	test(t_pipe_util *util, t_fd *fd, char **envp, char **argv)
{
	int	i;

	fd->child_pid = malloc(util->cnt_cmds * sizeof(*(fd->child_pid)));
	if (fd->child_pid == NULL)
		return (FAILURE);
	i = 0;
	fd->input_fd = fd->infile_fd;
	while (i < util->cnt_cmds)
	{
		if (i == util->cnt_cmds - 1)
		{
			if (exec_last_cmd(i, util, fd, envp, argv) == -1)
				return (FAILURE);
		}
		else if (exec_cmd(i, util, fd, envp, argv) == -1)
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < util->cnt_cmds)
		waitpid(fd->child_pid[i++], NULL, 0);
	return (SUCCESS);
}

int	exec_last_cmd(int i, t_pipe_util *util, t_fd *fd, char **envp, char **argv)
{
	fd->child_pid[i] = fork();
	if (fd->child_pid[i] == -1)
		return (print_errno(argv, "fork failed"), FAILURE);
	if (fd->child_pid[i] > 0)
		close(fd->input_fd);
	else if (fd->child_pid[i] == 0)
		exec_child_p(i, fd, util, envp, argv);
	return (SUCCESS);
}

int	exec_cmd(int i, t_pipe_util *util, t_fd *fd, char **envp, char **argv)
{
	if (pipe(fd->pd) == -1)
		return (print_errno(argv, "pipe failed"), FAILURE);
	fd->child_pid[i] = fork();
	if (fd->child_pid[i] == -1)
		return (print_errno(argv, "fork failed"), FAILURE);
	if (fd->child_pid[i] > 0)
	{
		close(fd->pd[1]);
		close(fd->input_fd);
	}
	else if (fd->child_pid[i] == 0)
		exec_child_p(i, fd, util, envp, argv);
	fd->input_fd = fd->pd[0];
	return (SUCCESS);
}

int	exec_child_p(int i, t_fd *fd, t_pipe_util *util, char **envp, char **argv)
{
	char	*exec_path;

	exec_path = find_exec_path(util, *(util->cmd_list[i]));
	dup2(fd->input_fd, 0);
	close(fd->input_fd);
	if (i == util->cnt_cmds - 1)
	{
		dup2(fd->outfile_fd, 1);
		close(fd->outfile_fd);
	}
	else
	{
		close(fd->pd[0]);
		dup2(fd->pd[1], 1);
		close(fd->pd[1]);
	}
	if (exec_path == NULL)
		if (exec_path == NULL)
			return (print_error_msg(argv, *(util->cmd_list[i])), FAILURE);
	if (execve(exec_path, util->cmd_list[i], envp) == -1)
		return (print_errno(argv, *(util->cmd_list[i])), FAILURE);
	return (SUCCESS);
}

/* 명령어 개수 세기 */
int	cnt_input_cmds(int argc)
{
	int	cnt_cmds;
	int	i;

	cnt_cmds = 0;
	i = 2;
	while (i < argc - 1)
	{
		i++;
		cnt_cmds++;
	}
	return (cnt_cmds);
}

/* input cmds 배열화 */
int	get_cmd_list(int argc, char	**argv, t_pipe_util *util)
{
	int		i;
	int		j;

	util->cnt_cmds = cnt_input_cmds(argc);
	util->cmd_list = ft_calloc(util->cnt_cmds, sizeof(*(util->cmd_list)));
	if (util->cmd_list == NULL)
		return (FAILURE);
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		util->cmd_list[j] = ft_split(argv[i], ' ');
		if (util->cmd_list[j] == NULL)
			return (FAILURE);
		i++;
		j++;
	}
	return (SUCCESS);
}

/* cmd_path 실행 가능 여부 확인 */
char	*find_exec_path(t_pipe_util *util, char *cmd) // 추가 예외 처리 필요
{
	char	*path_prefix;
	char	*exec_path;
	int		i;

	i = 0;
	while (util->dirs_path[i] != NULL)
	{
		path_prefix = append_str(util->dirs_path[i], "/");
		exec_path = append_str(path_prefix, cmd);
		if (access(exec_path, X_OK) != -1) // 실행 못 하면 건너뛰기
			return (exec_path);
		else
			i++;
	}
	return ((void *)0); // 직접 문구 처리 필요
}

int	create(t_pipe_util *util, t_fd *fd, char **argv, char **envp)
{
	fd->infile_fd = open(argv[1], O_RDONLY);
	if (fd->infile_fd == -1)
		print_errno(argv, argv[1]);
	fd->outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->outfile_fd == -1)
		print_errno(argv, argv[4]);
	if (fd->outfile_fd == -1 && fd->infile_fd == -1)
		return(FAILURE); // 프로그램 종료 하기
	if (!test(util, fd, envp, argv))
		return (FAILURE);
	return (SUCCESS);
}

/* 디렉터리별 path 추출 */
int	split_path_dirs(char **envp, t_pipe_util *util)
{
	int	i;
	int	n;

	i = 0;
	while (envp[i] != NULL)
	{
		n = get_idx_chr(envp[i], '=');
		if (n != NOT_FOUND)
		{
			if (ft_strncmp(envp[i], "PATH=", n) == 0)
			{
				util->dirs_path = ft_split(&envp[i][n + 1], ':');
				if (util->dirs_path == NULL)
					break ;
				else
					return (SUCCESS);
			}
		}
		i++;
	}
	return (FAILURE); // path가 없는 경우
}


/* PATH 문자열 탐색할 idx 찾기 */
int	get_idx_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NOT_FOUND);
		i++;
	}
	return (i);
}

void	print_errno(char **argv, char *error_obj)
{
	print_cur_exe_name(argv);
	perror(error_obj);
}

void	print_error_msg(char **argv, char *error_obj)
{
	print_cur_exe_name(argv);
	write(2, "command not found: ", ft_strlen("command not found: "));
	write(2, error_obj, ft_strlen(error_obj));
	write(2, "\n", 2);
}
void	print_cur_exe_name(char **argv)
{
	write(2, argv[0], ft_strlen(argv[0]));
	write(2, ": ", 2);
}
