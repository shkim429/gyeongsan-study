/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:28 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/05 12:28:27 by sohuikim         ###   ########.fr       */
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
int		split_path_dirs(char **envp, t_dirs_path *arr);
int	cnt_cmds(int argc);
int	get_cmd_list(int argc, char	**argv, t_input_var *var, t_dirs_path *path);
char	*find_exec_path(t_dirs_path *arr, char *cmd);
int	create(t_dirs_path *arr, char **argv, char **envp);
void	print_errno(char *error_name);

int	main(int argc, char **argv, char **envp)
{
	t_dirs_path	arr;
	t_input_var	var;
	int			i;
	char		*exec_path;

	if (argc != 5)
		return (FAILURE);
	else
	{
		i = 0;
		// print_errno(argv[0]);
		if (!split_path_dirs(envp, &arr))
			return (FAILURE);
		exec_path = find_exec_path(&arr, arr.cmd_list[0][0]);
		create(&arr, argv, envp);
	}
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
int	get_cmd_list(int argc, char	**argv, t_input_var *var, t_dirs_path *path)
{
	int		i;
	int		j;

	var->cnt_cmds = cnt_input_cmds(argc);
	path->cmd_list = ft_calloc(var->cnt_cmds, sizeof(*(path->cmd_list)));
	if (path->cmd_list == NULL)
		return (FAILURE);
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		path->cmd_list[j] = ft_split(argv[i], ' ');
		if (path->cmd_list[j] == NULL)
			return (FAILURE);
		i++;
		j++;
	}
	return (SUCCESS);
}

/* cmd_path 실행 가능 여부 확인 */
char	*find_exec_path(t_dirs_path *arr, char *cmd) // 추가 예외 처리 필요
{
	char	*path_prefix;
	char	*exec_path;
	int		i;

	i = 0;
	while (arr->dirs_path[i] != NULL)
	{
		path_prefix = append_str(arr->dirs_path[i], "/");
		exec_path = append_str(exec_path, cmd);
		if (access(exec_path, X_OK) != -1) // 실행 못 하면 건너뛰기
			return (exec_path);
		else
			i++;
	}
	return ((void *)0); // errno 처리 필요: errno 반환
}

/* 파이프fd 생성 */
int	create(t_dirs_path *arr, char **argv, char **envp)
{
	int	fd1;
	int	fd2;
	int	pd[2];
	pid_t	child1_pid;
	pid_t	child2_pid;
	
	if (pipe(pd) == -1) // 새 파이프 생성 (pd[0]: read end fd 할당, pd[1]: write end fd 할당)
		return (FAILURE); // PIPE_ERROR로 고치기
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		return (FAILURE); // errno 설정 필요
	fd2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd2 == -1)
		return (FAILURE); // errno 설정 필요
	child1_pid = fork();
	if (child1_pid < 0)
		return (FAILURE); // FORK_ERROR로 고치기
	if (child1_pid == 0) // 자식 p
	{
		close(pd[0]);
		dup2(fd1, 0);
		close(fd1);
		dup2(pd[1], 1); // 출력 (cmd1)
		close(pd[1]);
		char *str = test(arr, arr->cmd_list[0][0]);
		if (execve(str, arr->cmd_list[0], envp) == -1)
				return (exit(EXIT_FAILURE), FAILURE); // errno 설정 필요
	}
	child2_pid = fork();
	if (child2_pid == 0)
	{
		close(pd[1]);
		dup2(fd2, 1);
		close(fd2);
		dup2(pd[0], 0); // 입력 (cmd2)
		close(pd[0]);
		char *str = test(arr, arr->cmd_list[1][0]);
		if (execve(str, arr->cmd_list[1], envp) == -1)
			return (exit(EXIT_FAILURE), FAILURE);
	}
	 // 부모 p
	 close(pd[0]);
	 close(pd[1]);
	waitpid(child1_pid, NULL,0);
	waitpid(child2_pid, NULL, 0);

}	

/*
int	is_valid_file(char *file_name)
{
	int	fd;

	fd = file
}
*/

/* 디렉터리별 path 추출 */
int	split_path_dirs(char **envp, t_dirs_path *arr)
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
				arr->dirs_path = ft_split(&envp[i][n + 1], ':');
				if (arr->dirs_path == NULL)
					break ;
				else
					return (SUCCESS);
			}
		}
		i++;
	}
	return (FAILURE);
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
void	print_errno(char *error_name)
{
	// write(2, "./pipex: ", 9);
	perror(error_name);
}

int	valid_file(char *pathname, char *name)
{
	int	fd;

	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		perror(pathname); // 실행 파일 접두사도 출력해야 함
	    // 상대 경로도 가능해야 함
	}
	return (SUCCESS);
}