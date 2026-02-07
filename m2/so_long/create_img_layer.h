/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_layer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:16:05 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 16:00:03 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_IMG_LAYER_H
# define CREATE_IMG_LAYER_H

# include "so_long.h"

void	create_bg_layer(t_img *dst, t_comp *cmp, t_map *map);
int		create_player_layer(t_mlx_vars *vars, t_comp *cmp, t_map *map);
void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size);
void	copy_tile(t_img *dst, t_img *src, int row, int col);
void	create_tileset_layer(t_img *dst, t_comp *cmp, t_map *map);

#endif