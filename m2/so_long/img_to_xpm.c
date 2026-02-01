/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/02 03:40:34 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "img_to_xpm.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size);
void	copy_tile(t_img *dst, t_img *src, int row, int col);
/* img -> xpm 변환 */
void	load_xpm_img(const t_mlx_vars *vars, t_tileset *tileset, t_sprites *sprites)
{
	tileset->road.img = mlx_xpm_file_to_image(vars->mlx, "./textures/road.xpm", &tileset->road.img_w, &tileset->road.img_h);
	sprites->item.img = mlx_xpm_file_to_image(vars->mlx, "./textures/sweet_potato.xpm", &sprites->item.img_w, &sprites->item.img_h);
}

int	create_bg_layer(t_mlx_vars *vars, t_img *frame_buffer, t_tileset *tileset, t_map *dst_size)
{
	frame_buffer->img = mlx_new_image(vars->mlx, vars->win_x, vars->win_y); // 상위 함수로 이동하기
	tileset->road.img = mlx_xpm_file_to_image(vars->mlx, "./textures/road.xpm", &tileset->road.img_w, &tileset->road.img_h);
	frame_buffer->addr = mlx_get_data_addr(frame_buffer->img, &frame_buffer->bits_per_pixel, &frame_buffer->line_length, &frame_buffer->endian);
	tileset->road.addr = mlx_get_data_addr(tileset->road.img, &tileset->road.bits_per_pixel, &tileset->road.line_length, &tileset->road.endian);
	create_floor_layer(frame_buffer, &tileset->road, dst_size);
}
/*
void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size)
{
	int	dst_x;
	int	dst_y;

	dst_y = 0;
	while (dst_y < dst_size->cnt_row) // cnt_row = 4
	{
		dst_x = 0;
		while (dst_x < dst_size->cnt_column) // cnt_column = 5
		{
			copy_tile(dst, src, src->img_h * dst_y, src->img_w * dst_x); // 타일 단위 복제
			dst_x++;
		}
		dst_y++;
	}
}
*/

void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size)
{
	int	dst_x;
	int	dst_y;

	dst_y = 0;
	while (dst_y < dst_size->cnt_row)
	{
		dst_x = 0;
		while (dst_x < dst_size->cnt_column)
		{
			copy_tile(dst, src, src->img_h * dst_y, src->img_w * dst_x);
			dst_x++;
		}
		dst_y++;
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



/*
void	copy_tile(t_img *dst_img, t_tileset *src_img, int row, int column)
{
	char	*src_;
	char	*d

	src = tileset->road.addr + (row * tileset->road.line_length + column * (tileset->road.bits_per_pixel / 8));
	dst = frame_buffer->addr + (row * frame_buffer->line_length + column * (frame_buffer->bits_per_pixel / 8));
	ft_memcpy(dst, src, tileset->road.img_w * (tileset->road.bits_per_pixel / 8));
}
*/

