/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_layer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:16:05 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:18:58 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_IMG_LAYER_H
# define CREATE_IMG_LAYER_H

#include "so_long.h"

int	    create_bg_layer(t_img *frame_buffer, t_tileset *ts, t_map *map);
int	    create_spr_layer(t_mlx_vars *vars, t_sprites *spr, t_map *map);
void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size);
void	create_wall_layer(t_img *dst, t_img *src, t_map *map);
void	create_item_layer(t_img *dst, t_img *src, t_map *map);
void	copy_tile(t_img *dst, t_img *src, int row, int col);

#endif