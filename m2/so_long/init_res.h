/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 07:49:31 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 07:52:30 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_RES_H
# define INIT_RES_H

#include "so_long.h"

void	init_all_struct(t_mlx *vars, t_map_info *map, t_comp *cmp, t_game_info *game);
void	init_win(t_mlx *m_vars, t_map_info *map);

#endif