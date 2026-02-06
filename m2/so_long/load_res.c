/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:32:05 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_res.h"
#include "ft_libft.h"
#include "mlx.h"
#include <stdlib.h>

/* 이미지 읽어오기 */
int	load_res(const t_mlx_vars *vars, t_tileset *ts, t_sprites *spr)
{
	if (!load_floor_img(vars, ts))
		return (FAILURE);
	if (!load_item_img(vars, ts))
		return (FAILURE);
	if (!load_wall_img(vars, ts))
		return (FAILURE);
	if (!load_player_img(vars, spr))
		return (FAILURE);
	if (!load_exit_img(vars, spr));
}

int	load_floor_img(const t_mlx_vars *vars, t_tileset *ts)
{
	ts->floor.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/road.xpm", &ts->floor.img_w, &ts->floor.img_h);
	if (ts->floor.img == NULL)
		return (FAILURE);
	ts->floor.addr = mlx_get_data_addr(ts->floor.img, \
&ts->floor.bits_per_pixel, &ts->floor.line_length, &ts->floor.endian);
	return (SUCCESS);
}

int	load_wall_img(const t_mlx_vars *vars, t_tileset *ts)
{
	ts->car_rd_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/car_rd_r.xpm", &ts->car_rd_r.img_w, &ts->car_rd_r.img_h);
	if (ts->car_rd_r.img == NULL)
		return (FAILURE);
	ts->car_rd_r.addr = mlx_get_data_addr(ts->car_rd_r.img, \
&ts->car_rd_r.bits_per_pixel, &ts->car_rd_r.line_length, &ts->car_rd_r.endian);
	return (SUCCESS);
}

int	load_exit_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->exit.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/cart.xpm", &spr->exit.img_w, &spr->exit.img_h);
	if (spr->exit.img == NULL)
		return (FAILURE);
	spr->exit.addr = mlx_get_data_addr(spr->exit.img, \
&spr->exit.bits_per_pixel, &spr->exit.line_length, &spr->exit.endian);
	return (SUCCESS);
}
int	load_player_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->p_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_r.xpm", &spr->p_r.img_w, &spr->p_r.img_h);
	if (spr->p_r.img == NULL)
		return (FAILURE);
	spr->p_r.addr = mlx_get_data_addr(spr->p_r.img, \
&spr->p_r.bits_per_pixel, &spr->p_r.line_length, &spr->p_r.endian);
	return (SUCCESS);
}

int	load_item_img(const t_mlx_vars *vars, t_tileset *ts)
{
	ts->item.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/item.xpm", &ts->item.img_w, &ts->item.img_h);
	if (ts->item.img == NULL)
		return (FAILURE);
	ts->item.addr = mlx_get_data_addr(ts->item.img, \
	&ts->item.bits_per_pixel, &ts->item.line_length, &ts->item.endian);
}




