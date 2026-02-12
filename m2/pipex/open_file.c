/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:46:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:09:25 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_msg.h"
#include "free_res.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>

bool	open_infile(char **argv, t_pipe_util *pipe_util)
{
	pipe_util->fd->input_fd = open(argv[1], O_RDONLY);
	if (pipe_util->fd->input_fd == -1)
	{
		close (pipe_util->fd->pd[1]);
		print_errno(argv, argv[1]);
		free_res(pipe_util);
		return (false);
	}
	return (true);
}

bool	open_outfile(char **argv, t_pipe_util *pipe_util)
{
	pipe_util->fd->outfile_fd = open(argv[4], \
								O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (pipe_util->fd->outfile_fd == -1)
	{
		close(pipe_util->fd->pd[0]);
		print_errno(argv, argv[4]);
		free_res(pipe_util);
		return (false);
	}
	return (true);
}
