/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:54:57 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:12:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "exec_cmds.h"
#include "open_file.h"
#include "get_exec_path.h"
#include "print_msg.h"
#include "free_res.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

bool	run_cmd(char **envp, char **argv, t_pipe_util *pipe_util)
{
	int	i;

	pipe_util->fd->child_pid = malloc(pipe_util->cmd_path->cnt_cmds * \
								sizeof(*(pipe_util->fd->child_pid)));
	if (pipe_util->fd->child_pid == NULL)
		return (false);
	i = 0;
	while (i < pipe_util->cmd_path->cnt_cmds)
	{
		if (i == pipe_util->cmd_path->cnt_cmds - 1)
		{
			if (exec_last_cmd(envp, argv, pipe_util, i) == false)
				return (false);
		}
		else if (exec_cmd(envp, argv, pipe_util, i) == false)
			return (false);
		i++;
	}
	i = 0;
	while (i < pipe_util->cmd_path->cnt_cmds - 1)
		waitpid(pipe_util->fd->child_pid[i++], NULL, 0);
	waitpid(pipe_util->fd->child_pid[i], &pipe_util->child_status, 0);
	return (true);
}

bool	exec_cmd(char **envp, char **argv, t_pipe_util *pipe_util, int i)
{
	if (pipe(pipe_util->fd->pd) == -1)
		return (print_errno(argv, "pipe failed"), false);
	pipe_util->fd->child_pid[i] = fork();
	if (pipe_util->fd->child_pid[i] == -1)
		return (print_errno(argv, "fork failed"), false);
	if (pipe_util->fd->child_pid[i] > 0)
	{
		close(pipe_util->fd->pd[1]);
		if (i > 0)
			close(pipe_util->fd->input_fd);
	}
	else if (pipe_util->fd->child_pid[i] == 0)
	{
		close(pipe_util->fd->pd[0]);
		if (i == 0 && !open_infile(argv, pipe_util))
			exit(126);
		exec_child_p(envp, argv, pipe_util, i);
		close(pipe_util->fd->pd[1]);
		close(pipe_util->fd->input_fd);
		free_res(pipe_util);
		exit(127);
	}
	pipe_util->fd->input_fd = pipe_util->fd->pd[0];
	return (true);
}

bool	exec_last_cmd(char **envp, char **argv, t_pipe_util *pipe_util, int i)
{
	pipe_util->fd->child_pid[i] = fork();
	if (pipe_util->fd->child_pid[i] == -1)
	{
		print_errno(argv, "fork failed");
		return (false);
	}
	if (pipe_util->fd->child_pid[i] > 0)
		close(pipe_util->fd->input_fd);
	else if (pipe_util->fd->child_pid[i] == 0)
	{
		if (!open_outfile(argv, pipe_util))
			exit(1);
		exec_child_p(envp, argv, pipe_util, i);
		close(pipe_util->fd->pd[0]);
		close(pipe_util->fd->outfile_fd);
		free_res(pipe_util);
		exit(127);
	}
	return (true);
}

void	exec_child_p(char **envp, char **argv, t_pipe_util *pipe_util, int i)
{
	char	*exec_path;

	exec_path = find_exec_path(pipe_util->cmd_path, \
							*(pipe_util->cmd_path->cmd_list[i]));
	if (exec_path == NULL)
	{
		print_error_msg(argv, *(pipe_util->cmd_path->cmd_list[i]));
		return ;
	}
	if (!prepare_io(pipe_util, i))
	{
		free(exec_path);
		return ;
	}
	execve(exec_path, pipe_util->cmd_path->cmd_list[i], envp);
	print_error_msg(argv, *(pipe_util->cmd_path->cmd_list[i]));
	free(exec_path);
	return ;
}
