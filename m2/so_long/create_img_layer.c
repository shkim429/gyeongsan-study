/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:05:07 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:33:07 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_img_layer.h"
#include "load_res.h"
#include "mlx.h"

int	create_bg_layer(t_img *frame_buffer, t_tileset *ts, t_map *map)
{
	create_floor_layer(frame_buffer, &ts->floor, map);
	create_wall_layer(frame_buffer, &ts->car_rd_r, map);
	create_item_layer(frame_buffer, &ts->item, map);
}

int	create_spr_layer(t_mlx_vars *vars, t_sprites *spr, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, spr->exit.img, col * 50, row * 50);
			else if (map->arr[row][col] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, spr->p_r.img, col * 50, row * 50);
			col++;
		}
		row++;
	}
}
