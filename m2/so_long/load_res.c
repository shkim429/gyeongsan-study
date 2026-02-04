/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/04 03:21:06 by sohuikim         ###   ########.fr       */
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
	ts->car_rd_f.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/car_rd_f", &ts->car_rd_f.img_w, &ts->car_rd_f.img_h);
// 	ts->car_rd_r.img = mlx_xpm_file_to_image(vars->mlx, \
// "./textures/car_rd_r", &ts->car_rd_r.img_w, &ts->car_rd_r.img_h);
// 	ts->car_yl_f.img = mlx_xpm_file_to_image(vars->mlx, \
// "./textures/car_car_yl_f", &ts->car_yl_f.img_w, &ts->car_yl_f.img_h);
// 	ts->car_yl_r.img = mlx_xpm_file_to_image(vars->mlx, \
// "./textures/car_yl_r", &ts->car_yl_r.img_w, &ts->car_yl_r.img_h);
// 	ts->car_bl_f.img = mlx_xpm_file_to_image(vars->mlx, \
// "./textures/car_bl_f", &ts->car_bl_f.img_w, &ts->car_bl_f.img_h);
// 	ts->car_bl_r.img = mlx_xpm_file_to_image(vars->mlx, \
// "./textures/car_bl_r", &ts->car_bl_r.img_w, &ts->car_bl_r.img_h);
	ts->car_rd_f.addr = mlx_get_data_addr(ts->car_rd_f.img, \
&ts->car_rd_f.bits_per_pixel, &ts->car_rd_f.line_length, &ts->car_rd_f.endian);
// 	ts->car_rd_r.addr = mlx_get_data_addr(ts->car_rd_r.img, \
// &ts->car_rd_r.bits_per_pixel, &ts->car_rd_r.line_length, &ts->car_rd_r.endian);
// 	ts->car_yl_f.addr = mlx_get_data_addr(ts->car_yl_f.img, \
// &ts->car_yl_f.bits_per_pixel, &ts->car_yl_f.line_length, &ts->car_yl_f.endian);
// 	ts->car_yl_r.addr = mlx_get_data_addr(ts->car_yl_r.img, \
// &ts->car_yl_r.bits_per_pixel, &ts->car_yl_r.line_length, &ts->car_yl_r.endian);
// 	ts->car_bl_f.addr = mlx_get_data_addr(ts->car_bl_f.img, \
// &ts->car_bl_f.bits_per_pixel, &ts->car_bl_f.line_length, &ts->car_bl_f.endian);
// 	ts->car_bl_r.addr = mlx_get_data_addr(ts->car_bl_r.img, \
// &ts->car_bl_r.bits_per_pixel, &ts->car_bl_r.line_length, &ts->car_bl_r.endian);
}

int	load_player_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->p_f.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_f", &spr->p_f.img_w, &spr->p_f.img_h);
	spr->p_b.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_b", &spr->p_b.img_w, &spr->p_b.img_h);
	spr->p_l.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_l", &spr->p_l.img_w, &spr->p_l.img_h);
	spr->p_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_r", &spr->p_r.img_w, &spr->p_r.img_h);
	spr->p_run_l.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_run_l", &spr->p_run_l.img_w, &spr->p_run_l.img_h);
	spr->p_run_r.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/p_run_r", &spr->p_run_r.img_w, &spr->p_run_r.img_h);
	spr->p_f.addr = mlx_get_data_addr(spr->p_f.img, \
&spr->p_f.bits_per_pixel, &spr->p_f.line_length, &spr->p_f.endian);
	spr->p_b.addr = mlx_get_data_addr(spr->p_b.img, \
&spr->p_b.bits_per_pixel, &spr->p_b.line_length, &spr->p_b.endian);
	spr->p_l.addr = mlx_get_data_addr(spr->p_l.img, \
&spr->p_l.bits_per_pixel, &spr->p_l.line_length, &spr->p_l.endian);
	spr->p_r.addr = mlx_get_data_addr(spr->p_r.img, \
&spr->p_r.bits_per_pixel, &spr->p_r.line_length, &spr->p_r.endian);
	spr->p_run_l.addr = mlx_get_data_addr(spr->p_run_l.img, \
&spr->p_run_l.bits_per_pixel, &spr->p_run_l.line_length, &spr->p_run_l.endian);
	spr->p_run_r.addr = mlx_get_data_addr(spr->p_run_r.img, \
&spr->p_run_r.bits_per_pixel, &spr->p_run_r.line_length, &spr->p_run_r.endian);
}

int	load_item_img(const t_mlx_vars *vars, t_sprites *spr)
{
	spr->item.img = mlx_xpm_file_to_image(vars->mlx, "./textures/item.xpm", &spr->item.img_w, &spr->item.img_h);
	spr->item.addr = mlx_get_data_addr(spr->item.img, \
	&spr->item.bits_per_pixel, &spr->item.line_length, &spr->item.endian);
}

int	create_bg_layer(t_mlx_vars *vars, t_img *frame_buffer, t_tileset *ts, t_map *dst_size)
{
	frame_buffer->img = mlx_new_image(vars->mlx, vars->win_x, vars->win_y); // 상위 함수로 이동하기
	frame_buffer->addr = mlx_get_data_addr(frame_buffer->img, &frame_buffer->bits_per_pixel, &frame_buffer->line_length, &frame_buffer->endian);
	if (!load_floor_img(vars, ts))
		return (FAILURE);
	if (!load_wall_img(vars, ts))
		return (FAILURE);
	create_floor_layer(frame_buffer, &ts->floor, dst_size);
	create_wall_layer(frame_buffer, &ts->car_bl_f, dst_size);
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

void	create_wall_layer(t_img *dst, t_img *src, t_map *map)
{
	int	dst_x;
	int	dst_y;

	dst_x = 0;
	while(map->cnt_row) // row = 4
	{
		dst_y = 0;
		while (map->cnt_column) // col = 5
		{
			if (map->arr[dst_y][dst_x] == '1')
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


