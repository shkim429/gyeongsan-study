/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bg_layer_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:06:12 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:34:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_img_layer.h"
#include "ft_libft.h"

void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size)
{
	int	dst_x;
	int	dst_y;

	dst_y = 0;
	while (dst_y < dst_size->cnt_row)
	{
		dst_x = 0;
		while (dst_x < dst_size->cnt_col)
		{
			copy_tile(dst, src, src->img_h * dst_y, src->img_w * dst_x);
			dst_x++;
		}
		dst_y++;
	}
}

void	create_wall_layer(t_img *dst, t_img *src, t_map *map)
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
				copy_tile(dst, src, src->img_h * row, src->img_w * col);
			col++;
		}
		row++;
	}
}

void	create_item_layer(t_img *dst, t_img *src, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == 'C')
				copy_tile(dst, src, src->img_h * row, src->img_w * col);
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
