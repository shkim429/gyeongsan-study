/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 15:36:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_res.h"
#include "ft_libft.h"
#include "mlx.h"
#include <stdlib.h>

/* 이미지 읽어오기 */
int	load_res(const t_mlx_vars *vars, t_comp *cmp)
{
	if (!load_floor_img(vars, cmp))
		return (FAILURE);
	if (!load_item_img(vars, cmp))
		return (FAILURE);
	if (!load_wall_img(vars, cmp))
		return (FAILURE);
	if (!load_exit_img(vars, cmp))
		return (FAILURE);
	if (!load_player_img(vars, cmp))
		return (FAILURE);
}

int	load_floor_img(const t_mlx_vars *vars, t_comp *cmp)
{
	cmp->floor.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/road.xpm", &cmp->floor.img_w, &cmp->floor.img_h);
	if (cmp->floor.img == NULL)
		return (FAILURE);
	cmp->floor.addr = mlx_get_data_addr(cmp->floor.img, \
&cmp->floor.bits_per_pixel, &cmp->floor.line_length, &cmp->floor.endian);
	return (SUCCESS);
}

int	load_wall_img(const t_mlx_vars *vars, t_comp *cmp)
{
	cmp->car_rd_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/car_rd_r.xpm", &cmp->car_rd_r.img_w, &cmp->car_rd_r.img_h);
	if (cmp->car_rd_r.img == NULL)
		return (FAILURE);
	cmp->car_rd_r.addr = mlx_get_data_addr(cmp->car_rd_r.img, \
&cmp->car_rd_r.bits_per_pixel, &cmp->car_rd_r.line_length, &cmp->car_rd_r.endian);
	return (SUCCESS);
}

int	load_exit_img(const t_mlx_vars *vars, t_comp *cmp)
{
	cmp->exit.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/cart.xpm", &cmp->exit.img_w, &cmp->exit.img_h);
	if (cmp->exit.img == NULL)
		return (FAILURE);
	cmp->exit.addr = mlx_get_data_addr(cmp->exit.img, \
&cmp->exit.bits_per_pixel, &cmp->exit.line_length, &cmp->exit.endian);
	return (SUCCESS);
}

int	load_player_img(const t_mlx_vars *vars, t_comp *cmp)
{
	cmp->p_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_r.xpm", &cmp->p_r.img_w, &cmp->p_r.img_h);
	if (cmp->p_r.img == NULL)
		return (FAILURE);
	cmp->p_r.addr = mlx_get_data_addr(cmp->p_r.img, \
&cmp->p_r.bits_per_pixel, &cmp->p_r.line_length, &cmp->p_r.endian);
	return (SUCCESS);
}

int	load_item_img(const t_mlx_vars *vars, t_comp *cmp)
{
	cmp->item.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/item.xpm", &cmp->item.img_w, &cmp->item.img_h);
	if (cmp->item.img == NULL)
		return (FAILURE);
	cmp->item.addr = mlx_get_data_addr(cmp->item.img, \
	&cmp->item.bits_per_pixel, &cmp->item.line_length, &cmp->item.endian);
}




