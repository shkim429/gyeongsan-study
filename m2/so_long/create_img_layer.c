/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:05:07 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 16:00:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_img_layer.h"
#include "load_res.h"
#include "mlx.h"

void	create_bg_layer(t_img *dst, t_comp *cmp, t_map *map)
{
	create_floor_layer(dst, &cmp->floor, map);
	create_tileset_layer(dst, cmp, map);
}

int	create_player_layer(t_mlx_vars *vars, t_comp *cmp, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == 'P')
				mlx_put_image_to_window(vars->mlx, \
					vars->win, cmp->p_r.img, col * 50, row * 50);
			col++;
		}
		row++;
	}
}

void	create_floor_layer(t_img *dst, t_img *src, t_map *map)
{
	int	dst_x;
	int	dst_y;

	dst_y = 0;
	while (dst_y < map->cnt_row)
	{
		dst_x = 0;
		while (dst_x < map->cnt_col)
		{
			copy_tile(dst, src, src->img_h * dst_y, src->img_w * dst_x);
			dst_x++;
		}
		dst_y++;
	}
}

void	create_tileset_layer(t_img *dst, t_comp *cmp, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == '1')
				copy_tile(dst, &cmp->car_rd_r.img, \
					cmp->car_rd_r.img_h * row, cmp->car_rd_r.img_w * col);
			else if (map->arr[row][col] == 'C')
				copy_tile(dst, &cmp->item.img, \
					cmp->item.img_h * row, cmp->item.img_w * col);
			else if (map->arr[row][col] == 'E')
				copy_tile(dst, &cmp->exit.img, \
					cmp->exit.img_h * row, cmp->exit.img_w * col);
			col++;
		}
		row++;
	}
}

void	copy_tile(t_img *dst, t_img *src, int row, int col)
{
	char	*src_pos;
	char	*dst_pos;
	int		src_y;

	src_y = 0;
	while (src_y < src->img_h)
	{
		src_pos = src->addr + (src_y * src->line_length + 0 * (src->bits_per_pixel / 8));
		dst_pos = dst->addr + ((row + src_y) * dst->line_length) + (col * (dst->bits_per_pixel / 8));
		ft_memcpy(dst_pos, src_pos, src->img_w * (src->bits_per_pixel / 8));
		src_y++;
	}
}
