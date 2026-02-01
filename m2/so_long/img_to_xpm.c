/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/02 01:00:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "img_to_xpm.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	copy_tile(t_img *dst, t_img *src, int row, int col);
/* img -> xpm 변환 */
void	load_xpm_img(const t_mlx_vars *vars, t_tileset *tileset, t_sprites *sprites)
{
	tileset->road.img = mlx_xpm_file_to_image(vars->mlx, "./textures/road.xpm", &tileset->road.img_w, &tileset->road.img_h);
	sprites->item.img = mlx_xpm_file_to_image(vars->mlx, "./textures/sweet_potato.xpm", &sprites->item.img_w, &sprites->item.img_h);
}

int	create_bg_layer(t_mlx_vars *vars, t_img *frame_buffer, t_tileset *tileset)
{
	frame_buffer->img = mlx_new_image(vars->mlx, vars->win_x, vars->win_y);
	tileset->road.img = mlx_xpm_file_to_image(vars->mlx, "./textures/road.xpm", &tileset->road.img_w, &tileset->road.img_h);
	frame_buffer->addr = mlx_get_data_addr(frame_buffer->img, &frame_buffer->bits_per_pixel, &frame_buffer->line_length, &frame_buffer->endian);
	tileset->road.addr = mlx_get_data_addr(tileset->road.img, &tileset->road.bits_per_pixel, &tileset->road.line_length, &tileset->road.endian);

	copy_tile(frame_buffer, &tileset->road, 0, 0); // 타일 단위 복제
	printf("%p\n", frame_buffer->addr);
	printf("%p\n", tileset->road.addr);
	printf("line_length: %d\n", tileset->road.line_length);
	printf("endian: %d\n", tileset->road.endian);
	printf("bits_per_pixel: %d\n", tileset->road.bits_per_pixel);
	printf("img_h: %d\n", tileset->road.img_h);
	printf("img_w: %d\n", tileset->road.img_w);

}

/*
void	create_floor_layer(t_img *dst, t_img *src)
{
	while ()
	{
		copy_tile(dst, src, );
	}
}
	*/

void	copy_tile(t_img *dst, t_img *src, int row, int col)
{
	char	*src_pos;
	char	*dst_pos;
	int		i;
	int		j;

	i = 0;
	while (row < src->img_h)
	{
		src_pos = src->addr + (row * src->line_length + col * (src->bits_per_pixel / 8));
		dst_pos = dst->addr + (row * dst->line_length + col * (dst->bits_per_pixel / 8)); // 이거 바꾸어야 함
		ft_memcpy(dst_pos, src_pos, src->img_w * (src->bits_per_pixel / 8)); // 한 줄 복사(고정)
		i++;
		row++;
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

