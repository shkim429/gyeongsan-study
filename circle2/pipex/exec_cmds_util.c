/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:14:36 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/12 21:43:25 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec_cmds.h"
#include "print_msg.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

bool	prepare_io(t_pipe_util *pipe_util, int i)
{
	if (dup2(pipe_util->fd->input_fd, 0) < 0)
	{
		close(pipe_util->fd->input_fd);
		return (false);
	}
	if (i == pipe_util->cmd_path->cnt_cmds - 1)
	{
		if (dup2(pipe_util->fd->outfile_fd, 1) < 0)
			return (false);
		close(pipe_util->fd->outfile_fd);
	}
	else
	{
		close(pipe_util->fd->input_fd);
		if (dup2(pipe_util->fd->pd[1], 1) < 0)
		{
			close(pipe_util->fd->pd[1]);
			return (false);
		}
		close(pipe_util->fd->pd[1]);
	}
	return (true);
}
