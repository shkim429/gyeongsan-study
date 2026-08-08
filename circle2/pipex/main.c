/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:28 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:49:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "exec_cmds.h"
#include "get_exec_path.h"
#include "print_msg.h"
#include "free_res.h"
#include "ft_libft.h"
#include "errno.h"
#include <sys/wait.h>

void	return_child_status(t_pipe_util *pipe_util);

int	main(int argc, char **argv, char **envp)
{
	t_pipe_util	pipe_util;
	t_cmd_path	cmd_path;
	t_fd		fd;

	if (argc != 5)
		return (1);
	init_all_struct(&pipe_util, &cmd_path, &fd);
	bind_struct(&pipe_util, &cmd_path, &fd);
	if (!split_path_dirs(envp, &cmd_path))
		return (1);
	if (!get_cmd_list(argc, argv, &cmd_path))
	{
		free_res(&pipe_util);
		return (1);
	}
	if (!run_cmd(envp, argv, &pipe_util))
	{
		free_res(&pipe_util);
		return (1);
	}
	free_res(&pipe_util);
	return_child_status(&pipe_util);
}
