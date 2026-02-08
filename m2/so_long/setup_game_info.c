/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 06:54:56 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 07:17:26 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_game_info(t_game_info *game, t_mlx *m_vars, t_comp *cmp, \
						t_map_info *map)
{
	game->mlx = m_vars;
	game->cmp = cmp;
	game->map = map;
}
