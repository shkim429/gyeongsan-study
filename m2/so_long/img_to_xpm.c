/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/31 03:33:51 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "img_to_xpm.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	*copy_tile(t_img *frame_buffer, t_tileset *tileset, int	x, int y);
/* img -> xpm 변환 */
void	load_xpm_img(const t_mlx_vars *vars, t_tileset *tileset, t_sprites *sprites)
{
	tileset->road.img = mlx_xpm_file_to_image(vars->mlx, "./textures/road.xpm", &tileset->road.img_w, &tileset->road.img_h);
	sprites->item.img = mlx_xpm_file_to_image(vars->mlx, "./textures/sweet_potato.xpm", &sprites->item.img_w, &sprites->item.img_h);
}

int	create_bg_layer(t_mlx_vars *vars, t_img *frame_buffer, t_tileset *tileset)
{
	frame_buffer->img = mlx_new_image(vars->mlx, vars->win_x, vars->win_y);
	frame_buffer->addr = mlx_get_data_addr(frame_buffer->img, &frame_buffer->bits_per_pixel, &frame_buffer->line_length, &frame_buffer->endian);
	tileset->road.img = mlx_xpm_file_to_image(vars->mlx, "./textures/road.xpm", &tileset->road.img_w, &tileset->road.img_h);
	tileset->road.addr = mlx_get_data_addr(tileset->road.img, &tileset->road.bits_per_pixel, &tileset->road.line_length, &tileset->road.endian);
	printf("%p\n", frame_buffer->addr);
	printf("%p\n", tileset->road.addr);
	printf("line_length: %d\n", tileset->road.line_length);
	printf("endian: %d\n", tileset->road.endian);
	printf("bits_per_pixel: %d\n", tileset->road.bits_per_pixel);
	printf("img_h: %d\n", tileset->road.img_h);
	printf("img_w: %d\n", tileset->road.img_w);
	// char *dst1 = frame_buffer->addr + (0 * frame_buffer->line_length + 0 * (frame_buffer->bits_per_pixel)/8);
	unsigned int dst1 = *(unsigned int *)frame_buffer->addr + (100 * tileset->road.line_length + 100 * (tileset->road.bits_per_pixel)/8);
	char *dst = copy_tile(frame_buffer, tileset, 0, 0);
	unsigned int dst3 = *(unsigned int *)tileset->road.addr + (100 * tileset->road.line_length + 100 * (tileset->road.bits_per_pixel)/8);

	printf("dst1: 0x%08x\n", dst1);
	printf("dst3: 0x%08x\n", dst3);



}

void	*copy_tile(t_img *frame_buffer, t_tileset *tileset, int	x, int y)
{
	char	*src;
	char	*dst;
	char	*src1;

	src = tileset->road.addr + (y * tileset->road.line_length + x * (tileset->road.bits_per_pixel / 8));
	dst = frame_buffer->addr + (y * frame_buffer->line_length + x * (frame_buffer->bits_per_pixel / 8));

	dst = ft_memcpy(dst, src, 49);
	return (dst);

}
