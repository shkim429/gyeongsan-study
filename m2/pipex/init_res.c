/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 16:29:25 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/12 17:15:32 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_libft.h"

void	init_all_struct(t_pipe_util *pipe_util, t_cmd_path *cmd_path, t_fd *fd)
{
	ft_bzero(pipe_util, sizeof(t_pipe_util));
	ft_bzero(cmd_path, sizeof(t_cmd_path));
	ft_bzero(fd, sizeof(t_fd));
}

void	bind_struct(t_pipe_util *pipe_util, t_cmd_path *cmd_path, t_fd *fd)
{
	pipe_util->cmd_path = cmd_path;
	pipe_util->fd = fd;
}
