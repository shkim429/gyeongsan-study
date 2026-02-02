/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/02 18:38:32 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_RES_H
# define LOAD_RES_H

# include "so_long.h"
# include "map_validate.h"

typedef struct s_tileset
{
	t_img	floor;
	t_img	car_rd_f;
	t_img	car_rd_b;
	t_img	car_rd_l;
	t_img	car_rd_r;
	t_img	car_gn_f;
	t_img	car_gn_b;
	t_img	car_gn_l;
	t_img	car_gn_r;
	t_img	car_bl_f;
	t_img	car_bl_b;
	t_img	car_bl_l;
	t_img	car_bl_r;
	t_img	car_yl_f;
	t_img	car_yl_b;
	t_img	car_yl_l;
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

typedef enum s_facing_state
{
	BACK,
	FRONT,
	LEFT,
	RRIGHT
}	t_facing_state;

int	create_bg_layer(t_mlx_vars *vars, t_img *frame_buffer, t_tileset *tileset, t_map *dst_size);

#endif