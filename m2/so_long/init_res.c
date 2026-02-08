/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 06:53:53 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 07:56:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_res.h"

void	init_all_struct(t_mlx *vars, t_map_info *map, t_comp *cmp, t_game_info *game)
{
	ft_bzero(vars, sizeof(t_mlx));
	ft_bzero(vars, sizeof(t_map_info));
	ft_bzero(cmp, sizeof(t_comp));
	ft_bzero(game, sizeof(t_game_info));
}

void	init_win(t_mlx *m_vars, t_map_info *map)
{
	int	tile_size;

	tile_size = 50;
	m_vars->win_x = tile_size * map->cnt_col;
	m_vars->win_y = tile_size * map->cnt_row;
	m_vars->win = mlx_new_window(m_vars->mlx, m_vars->win_x, m_vars->win_y, \
								"sohuikim");
}
