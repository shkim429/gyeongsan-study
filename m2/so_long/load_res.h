/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/05 03:25:31 by sohuikim         ###   ########.fr       */
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

typedef struct s_sprites
{
	t_img	item;
	t_img	exit;
	t_img	p_f;
	t_img	p_b;
	t_img	p_l;
	t_img	p_run_l;
	t_img	p_r;
	t_img	p_run_r;
}	t_sprites;

typedef struct s_img_table
{
	char	**path;
	t_img	*out_img;

}	t_img_table;


int	create_bg_layer(t_img *frame_buffer, t_tileset *ts, t_map *dst_size);
int	create_spr_layer(t_img *frame_buffer, t_sprites *spr, t_map *map);
void	create_player_layer(t_img *dst, t_img *src, t_map *map);
void	create_item_layer(t_img *dst, t_img *src, t_map *map);
void	create_exit_layer(t_img *dst, t_img *src, t_map *map);
int	load_res(const t_mlx_vars *vars, t_tileset *ts, t_sprites *spr);
#endif