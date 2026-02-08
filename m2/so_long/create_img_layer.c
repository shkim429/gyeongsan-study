/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_layer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:05:07 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 18:42:52 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_img_layer.h"
#include "load_res.h"
#include "mlx.h"
#include "ft_libft.h"
#include <stdlib.h>

int	create_bg_layer(t_mlx *m_vars, t_comp *cmp, t_map_info *map)
{
	cmp->frame.img = mlx_new_image(m_vars->mlx, m_vars->win_x, m_vars->win_y);
	if (cmp->frame.img == NULL)
		return (FAILURE);
	cmp->frame.addr = mlx_get_data_addr(cmp->frame.img, &cmp->frame.bpp, \
		&cmp->frame.line_len, &cmp->frame.endian);
	create_floor_layer(&cmp->frame, &cmp->floor, map);
	create_tileset_layer(&cmp->frame, cmp, map);
	return (SUCCESS);
}

void	create_floor_layer(t_img_info *dst, t_img_info *src, t_map_info *map)
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

void	create_tileset_layer(t_img_info *dst, t_comp *cmp, t_map_info *map)
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
				copy_tile(dst, &cmp->wall, \
					cmp->wall.img_h * row, cmp->wall.img_w * col);
			else if (map->arr[row][col] == 'C')
				copy_tile(dst, &cmp->item, \
					cmp->item.img_h * row, cmp->item.img_w * col);
			else if (map->arr[row][col] == 'E')
				copy_tile(dst, &cmp->exit, \
					cmp->exit.img_h * row, cmp->exit.img_w * col);
			col++;
		}
		row++;
	}
}

void	create_player_layer(t_mlx *m_vars, t_comp *cmp, t_map_info *map)
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
				mlx_put_image_to_window(m_vars->mlx, \
					m_vars->win, cmp->player.img, col * 50, row * 50);
			col++;
		}
		row++;
	}
}

void	copy_tile(t_img_info *dst, t_img_info *src, int row, int col)
{
	char	*src_pos;
	char	*dst_pos;
	int		src_y;

	src_y = 0;
	while (src_y < src->img_h)
	{
		src_pos = src->addr + \
		(src_y * src->line_len + 0 * (src->bpp / 8));
		dst_pos = dst->addr + \
		((row + src_y) * dst->line_len) + (col * (dst->bpp / 8));
		ft_memcpy(dst_pos, src_pos, src->img_w * (src->bpp / 8));
		src_y++;
	}
}
