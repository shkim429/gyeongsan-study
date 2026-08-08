/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:08:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/12 16:56:39 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_RES_H
# define FREE_RES_H

# include "pipex.h"

void	free_dirs_path(t_cmd_path *cmd_path);
void	free_cmd_list(t_cmd_path *cmd_path);
void	free_res(t_pipe_util *pipe_util);

#endif