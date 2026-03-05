/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:10:07 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/12 16:56:14 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	free_dirs_path(t_cmd_path *cmd_path)
{
	int	i;

	i = 0;
	while (cmd_path->dirs_path[i] != NULL)
	{
		free(cmd_path->dirs_path[i]);
		i++;
	}
	free(cmd_path->dirs_path);
	cmd_path->dirs_path = NULL;
}

void	free_cmd_list(t_cmd_path *cmd_path)
{
	int	i;
	int	j;

	i = 0;
	while (cmd_path->cmd_list[i] != NULL)
	{
		j = 0;
		while (cmd_path->cmd_list[i][j] != NULL)
		{
			free(cmd_path->cmd_list[i][j]);
			j++;
		}
		free(cmd_path->cmd_list[i]);
		cmd_path->cmd_list[i] = NULL;
		i++;
	}
	free(cmd_path->cmd_list);
	cmd_path->cmd_list = NULL;
}

void	free_child_pd_arr(t_fd *fd)
{
	free(fd->child_pid);
	fd->child_pid = NULL;
}

void	free_res(t_pipe_util *pipe_util)
{
	if (pipe_util->cmd_path->dirs_path != NULL)
		free_dirs_path(pipe_util->cmd_path);
	if (pipe_util->cmd_path->cmd_list != NULL)
		free_cmd_list(pipe_util->cmd_path);
	if (pipe_util->fd->child_pid != NULL)
		free_child_pd_arr(pipe_util->fd);
}
