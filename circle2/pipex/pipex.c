/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:28 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/11 15:47:23 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ft_libft.h"
#include "free_res.h"
#include "get_cmd_list_util.h"

int		valid_file(char *pathname, char *name);
int		get_idx_chr(char *str, char c);
int		split_path_dirs(char **envp, t_cmd_path *util);
int		cnt_input_cmds(int argc);
int		get_cmd_list(int argc, char	**argv, t_cmd_path *util);
char	*find_exec_path(t_cmd_path *arr, char *cmd);
int		create(t_cmd_path *util, t_fd *fd, char **argv, char **envp);
void	print_errno(char **argv, char *error_obj);
int		exec_child_p(int i, t_fd *fd, t_cmd_path *util, char **envp, char **argv);
int		run_cmd(t_cmd_path *path, t_fd *fd, char **envp, char **argv);
int		exec_last_cmd(int i, t_cmd_path *util, t_fd *fd, char **envp, char **argv);
int		exec_cmd(int i, t_cmd_path *util, t_fd *fd, char **envp, char **argv);
void	init_all_struct(t_cmd_path *util, t_fd *fd);

int	main(int argc, char **argv, char **envp)
{
	t_cmd_path	util;
	t_fd		fd;
	t_exe_var	exe_var;

	if (argc != 5)
		return (FAILURE);
	else
	{
		bind_exe_var(&exe_var, argv, envp);
		init_all_struct(&util, &fd);
		if (!split_path_dirs(envp, &util))
			return (FAILURE);
		if (!get_cmd_list(argc, argv, &util))
			return (free_res(&util, &fd), FAILURE);
		if (!run_cmd(&util, &fd, envp, argv))
			return (free_res(&util, &fd), FAILURE);
		return (free_res(&util, &fd), SUCCESS);
	}
}

void	bind_exe_var(t_exe_var *exe_var, char **argv, char **envp)
{
	exe_var->argv_addr = argv;
	exe_var->envp_addr = envp;
}

void	init_all_struct(t_cmd_path *util, t_fd *fd)
{
	ft_bzero(util, sizeof(t_cmd_path));
	ft_bzero(fd, sizeof(t_fd));
}

int	run_cmd(t_cmd_path *util, t_fd *fd, char **envp, char **argv)
{
	int	i;

	fd->child_pid = malloc(util->cnt_cmds * sizeof(*(fd->child_pid)));
	if (fd->child_pid == NULL)
		return (FAILURE);
	i = 0;
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

int	exec_last_cmd(int i, t_cmd_path *util, t_fd *fd, char **envp, char **argv)
{
	fd->child_pid[i] = fork();
	if (fd->child_pid[i] == -1)
		return (print_errno(argv, "fork failed"), FAILURE);
	if (fd->child_pid[i] > 0)
		close(fd->input_fd);
	else if (fd->child_pid[i] == 0)
	{
		fd->outfile_fd = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd->outfile_fd == -1)
		{
			print_errno(argv, argv[4]);
			free_res(util, fd);
			exit(EXIT_FAILURE);
		}

		exec_child_p(i, fd, util, envp, argv);
	}
	return (SUCCESS);
}

int	exec_cmd(int i, t_cmd_path *util, t_fd *fd, char **envp, char **argv)
{
	if (pipe(fd->pd) == -1)
		return (print_errno(argv, "pipe failed"), FAILURE);
	fd->child_pid[i] = fork();
	if (fd->child_pid[i] == -1)
		return (print_errno(argv, "fork failed"), FAILURE);
	if (fd->child_pid[i] > 0)
	{
		close(fd->pd[1]);
		if (i > 0)
			close(fd->input_fd);
	}
	else if (fd->child_pid[i] == 0)
	{
		if (i == 0)
		{
			fd->infile_fd = open(argv[1], O_RDONLY);
			if (fd->infile_fd == -1)
				return (print_errno(argv, argv[1]), (free_res(util, fd), \
				exit(EXIT_FAILURE), FAILURE));
			fd->input_fd = fd->infile_fd;
		}
		exec_child_p(i, fd, util, envp, argv);
	}
	fd->input_fd = fd->pd[0];
	return (SUCCESS);
}

int	exec_child_p(int i, t_fd *fd, t_cmd_path *util, char **envp, char **argv)
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
	if (exec_path == NULL || execve(exec_path, util->cmd_list[i], envp) == -1)
	{
		print_error_msg(argv, *(util->cmd_list[i]));
		free_res(util, fd);
		free(exec_path);
		exit(EXIT_FAILURE);
	}
	return (free(exec_path), SUCCESS);
}




char	*find_exec_path(t_pipe_util *util, char *cmd)
{
	char	*path_prefix;
	char	*exec_path;
	int		i;

	i = 0;
	while (util->dirs_path[i] != NULL)
	{
		path_prefix = ft_strjoin(util->dirs_path[i], "/");
		exec_path = ft_strjoin(path_prefix, cmd);
		free(path_prefix);
		if (access(exec_path, X_OK) != -1)
			return (exec_path);
		else
		{
			free(exec_path);
			i++;
		}
	}
	return (NULL);
}








