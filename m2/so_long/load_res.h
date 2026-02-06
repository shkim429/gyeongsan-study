/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/06 18:30:23 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_RES_H
# define LOAD_RES_H

# include "so_long.h"
# include "map_validate.h"

typedef struct s_tileset
{
	t_img	floor;
	t_img	car_rd_r;
	t_img	car_gn_r;
	t_img	car_yl_r;
}	t_tileset;

int	create_bg_layer(t_img *frame_buffer, t_tileset *ts, t_map *dst_size);
int	create_spr_layer(t_mlx_vars *vars, t_sprites *spr, t_map *map);
void	create_player_layer(t_img *dst, t_img *src, t_map *map);
void	create_item_layer(t_img *dst, t_img *src, t_map *map);
void	create_exit_layer(t_img *dst, t_img *src, t_map *map);
int	load_res(const t_mlx_vars *vars, t_tileset *ts, t_sprites *spr);
#endif