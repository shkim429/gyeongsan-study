/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 21:10:07 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 17:01:49 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	free_dirs_path(t_pipe_util *util)
{
	int	i;

	i = 0;
	while (util->dirs_path[i] != NULL)
	{
		free(util->dirs_path[i]);
		i++;
	}
	free(util->dirs_path);
	util->dirs_path = NULL;
}

void	free_cmd_list(t_pipe_util *util)
{
	int	i;
	int	j;

	i = 0;
	while (util->cmd_list[i] != NULL)
	{
		j = 0;
		while (util->cmd_list[i][j] != NULL)
		{
			free(util->cmd_list[i][j]);
			j++;
		}
		free(util->cmd_list[i]);
		util->cmd_list[i] = NULL;
		i++;
	}
	free(util->cmd_list);
	util->cmd_list = NULL;
}

void	free_child_pd_arr(t_fd *fd)
{
	free(fd->child_pid);
	fd->child_pid = NULL;
}

void	free_res(t_pipe_util *util, t_fd *fd)
{
	if (util->dirs_path != NULL)
		free_dirs_path(util);
	if (util->cmd_list != NULL)
		free_cmd_list(util);
	if (fd->child_pid != NULL)
		free_child_pd_arr(fd);
}
