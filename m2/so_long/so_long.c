/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 03:08:58 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/14 14:30:38 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "map_validate.h"
#include "error.h"
#include "load_res.h"
#include "ft_libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		handle_exit_key(int keycode, t_mlx_vars *vars);
int	close_game(t_mlx_vars *vars);
int	handle_exit_mouse(t_mlx_vars *vars);
int	render_map(t_map *map);
int	is_valid_path(t_map *map);
int	is_valid_cnt_spr(t_map *map);
int	is_valid_game(t_map *map);
void	init_all_struct(t_mlx_vars *vars, t_img *frame, t_tileset *ts, t_sprites *spr);
void	dfs(t_map *map, bool *visit_arr, int row, int col);
void	get_plyaer_pos(t_map *map);

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc <= 1)
		return (print_error(), 0);
	ft_bzero(&map, sizeof(t_map));
	if (!read_map(argv[1], &map))
		return (FAILURE);
	if (!is_enclosed_by_walls(&map))
		return (FAILURE);
	if(!is_valid_game(&map))
		return (FAILURE);
	if (!render_map(&map))
		return (FAILURE);
	return (SUCCESS);
}

/* 창에 맵 화면 띄우기 */
int	render_map(t_map *map)
{
	t_mlx_vars	vars;
	t_img		frame_buffer;
	t_tileset	ts;
	t_sprites	spr;
	int			tile_size;

	tile_size = 50;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (FAILURE);
	// init_all_struct(&vars, &frame_buffer, &ts, &spr);
	vars.win_x = tile_size * map->cnt_column;
	vars.win_y = tile_size * map->cnt_row;
	vars.win = mlx_new_window(vars.mlx, vars.win_x, vars.win_y, "Hello world");
	frame_buffer.img = mlx_new_image(vars.mlx, vars.win_x, vars.win_y); 
	frame_buffer.addr = mlx_get_data_addr(frame_buffer.img, &frame_buffer.bits_per_pixel, &frame_buffer.line_length, &frame_buffer.endian);
	if (!load_res(&vars, &ts, &spr))
		return (FAILURE);
	create_bg_layer(&frame_buffer, &ts, map);
	create_spr_layer(&frame_buffer, &spr, map);
	mlx_put_image_to_window(vars.mlx, vars.win, frame_buffer.img, 0, 0);
	mlx_hook(vars.win, 2, 1L<<0, handle_exit_key, &vars);
	mlx_loop(vars.mlx);
	return (SUCCESS);
}

void	init_all_struct(t_mlx_vars *vars, t_img *frame, t_tileset *ts, t_sprites *spr)
{
	ft_bzero(vars, sizeof(t_mlx_vars));
	ft_bzero(frame, sizeof(t_img));
	ft_bzero(ts, sizeof(t_tileset));
	ft_bzero(spr, sizeof(t_sprites));
}

int	handle_exit_key(int keycode, t_mlx_vars *vars)
{
	if (keycode == XK_ESC)
		close_game(vars);
	return (0);
}

int	close_game(t_mlx_vars *vars)
{
	return (mlx_destroy_window(vars->mlx, vars->win), 0);
}


// /* map_path 유효성 검사 */
// void	is_valid_name(char *map_path)
// {
// 	is_vaild_format();
// 	if ()

// }

// void	is_valid_format()

int	is_valid_game(t_map *map)
{
	if (!is_valid_cnt_spr(map))
		return (FAILURE);
	if (!is_valid_path(map))
		return (FAILURE);
	return (SUCCESS);
}

int	is_valid_path(t_map *map)
{
	bool	*visit_arr;

	map->visit_cnt_c = 0;
	map->visit_cnt_e = 0;
	visit_arr = malloc((map->cnt_row * map->cnt_column) * sizeof(bool));
	if (visit_arr == NULL)
		return (FAILURE);
	ft_memset(visit_arr, false, map->cnt_row * map->cnt_column);
	get_plyaer_pos(map);
	dfs(map, visit_arr, map->p_x, map->p_y);
	if (map->visit_cnt_c != map->cnt_c || map->visit_cnt_e != map->cnt_e)
		return (FAILURE);
	return (SUCCESS);
}

void	get_plyaer_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == 'P')
			{
				map->p_x = row;
				map->p_y = col;
				return ;
			}
			col++;
		}
		row++;
	}
}


void	dfs(t_map *map, bool *visit_arr, int row, int col)
{
	if (row < 0 || row >= map->cnt_row || col < 0 || col >= map->cnt_column)
		return ;
	if (visit_arr[(row * map->cnt_column) + col] == true || map->arr[row][col] == '1')
		return ;
	if (map->arr[row][col] == 'C')
		map->visit_cnt_c++;
	if (map->arr[row][col] == 'E')
		map->visit_cnt_e++;
	visit_arr[(row * map->cnt_column) + col] = true;
	dfs(map, visit_arr, row - 1, col);
	dfs(map, visit_arr, row, col + 1);
	dfs(map, visit_arr, row + 1, col);
	dfs(map, visit_arr, row, col - 1);
}

int	is_valid_cnt_spr(t_map *map)
{
	int	row;
	int	col;

	map->cnt_c = 0;
	map->cnt_p = 0;
	map->cnt_e = 0;
	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_column)
		{
			if (map->arr[row][col] == 'C')
				map->cnt_c++;
			else if (map->arr[row][col] == 'E')
				map->cnt_e++;
			else if (map->arr[row][col] == 'P')
				map->cnt_p++;
			col++;
		}
		row++;
	}
	if (map->cnt_c <= 0 || map->cnt_p <= 0 || map->cnt_p > 1 || \
map->cnt_e <= 0 || map->cnt_e > 1)
		return (FAILURE);
	return (SUCCESS);
}
