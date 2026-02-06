/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/06 17:20:50 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "load_res.h"
#include "mlx.h"
#include "libft.h"
#include <stdio.h>

void	create_floor_layer(t_img *dst, t_img *src, t_map *dst_size);
void	copy_tile(t_img *dst, t_img *src, int row, int col);
int	load_floor_img(const t_mlx_vars *vars, t_tileset *ts);
int	load_wall_img(const t_mlx_vars *vars, t_tileset *ts);
int	load_player_img(const t_mlx_vars *vars, t_sprites *spr);
int	load_item_img(const t_mlx_vars *vars, t_sprites *spr);
void	create_wall_layer(t_img *dst, t_img *src, t_map *map);
void	create_exit_layer(t_img *dst, t_img *src, t_map *map);
int	load_exit_img(const t_mlx_vars *vars, t_sprites *spr);
/*
int	load_res_utiil(void)
{

	res[i].img = mlx_xpm_file_to_image(vars->mlx, res[i].path, res[i].img_w, res[i].img_h);
	if (res[i].img == NULL)
		return (FAILURE);
	res[i].addr = mlx_get_data_addr(res[i].img, \
res[i].bits_per_pixel, res[i].line_length, res[i].endian);
}

void	init_img_path(t_img_table *res)
{
	int	i;
	while (i < )
}

void	init_wall_path(t_img_table *res, t_facing_state *img_facing)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		res->path[i] = format("./texture/car_bl_%s.xpm", i);
	}
	
}

char	*format(char *str, int)
{
	char	*str_facing;

	if (str_facing == BACK)
}

char	*mapping_format_str(char *str, char c)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '%')
			str[j] = c;
	}
}
*/

/* 이미지 읽어오기 */
int	load_res(const t_mlx_vars *vars, t_tileset *ts, t_sprites *spr)
{
	if (!load_floor_img(vars, ts))
		return (FAILURE);
	if (!load_wall_img(vars, ts))
		return (FAILURE);
	if (!load_player_img(vars, spr))
		return (FAILURE);
	if (!load_item_img(vars, spr))
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

	ts->car_rd_r.addr = mlx_get_data_addr(ts->car_rd_r.img, \
&ts->car_rd_r.bits_per_pixel, &ts->car_rd_r.line_length, &ts->car_rd_r.endian);
}

int	load_exit_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->exit.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/cart.xpm", &spr->exit.img_w, &spr->exit.img_h);
	spr->exit.addr = mlx_get_data_addr(spr->exit.img, \
&spr->exit.bits_per_pixel, &spr->exit.line_length, &spr->exit.endian);
}
int	load_player_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->p_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_r.xpm", &spr->p_r.img_w, &spr->p_r.img_h);
	spr->p_r.addr = mlx_get_data_addr(spr->p_r.img, \
&spr->p_r.bits_per_pixel, &spr->p_r.line_length, &spr->p_r.endian);
}

int	load_item_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->item.img = mlx_xpm_file_to_image(vars->mlx, "./textures/item.xpm", &spr->item.img_w, &spr->item.img_h);
	spr->item.addr = mlx_get_data_addr(spr->item.img, \
	&spr->item.bits_per_pixel, &spr->item.line_length, &spr->item.endian);
}

int	create_bg_layer(t_img *frame_buffer, t_tileset *ts, t_map *map)
{
	create_floor_layer(frame_buffer, &ts->floor, map);
	create_wall_layer(frame_buffer, &ts->car_rd_r, map);
}

int	create_spr_layer(t_mlx_vars *vars, t_sprites *spr, t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, spr->item.img, col * 50, row * 50);
			else if (map->arr[row][col] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, spr->exit.img, col * 50, row * 50);
			else if (map->arr[row][col] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, spr->p_r.img, col * 50, row * 50);
			col++;
		}
		row++;
	}
}

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

void	create_player_layer(t_img *dst, t_img *src, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == 'P')
				return (copy_tile(dst, src, src->img_h * row, src->img_w * col));
			col++;
		}
		row++;
	}
}

void	create_exit_layer(t_img *dst, t_img *src, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == 'E')
				return (copy_tile(dst, src, src->img_h * row, src->img_w * col));
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
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == 'C')
				copy_tile(dst, src, src->img_h * row, src->img_w * col);
			col++;
		}
		row++;
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
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == '1')
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



