/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:08:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 16:35:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_RES_H
# define FREE_RES_H

# include "pipex.h"

void	free_dirs_path(t_pipe_util *util);
void	free_cmd_list(t_pipe_util *util);
void	free_res(t_pipe_util *util, t_fd *fd);
#endif