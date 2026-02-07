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
#include "valid_map.h"
#include "error.h"
#include "load_res.h"
#include "ft_libft.h"
#include "handle_frame.h"
#include "create_img_layer.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_map	map;
	t_ctx	ctx;

	if (argc <= 1)
		return (FAILURE);
	ft_bzero(&map, sizeof(t_map));
	if (!read_map(argv[1], &map))
		return (FAILURE);
	if (!is_valid_game(&map))
		return (FAILURE);
	if (!render_map(&map, &ctx))
		return (FAILURE);
	return (SUCCESS);
}

/* 창에 맵 화면 띄우기 */
int	render_map(t_map *map, t_ctx *ctx)
{
	t_mlx_vars	vars;
	t_img		buffer;
	t_comp		cmp;
	int			tile_size;

	tile_size = 50;
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (FAILURE);
	// init_all_struct(&vars, &frame_buffer, &ts, &spr);
	vars.win_x = tile_size * map->cnt_col;
	vars.win_y = tile_size * map->cnt_row;
	vars.win = mlx_new_window(vars.mlx, vars.win_x, vars.win_y, "Hello world");
	buffer.img = mlx_new_image(vars.mlx, vars.win_x, vars.win_y);
	buffer.addr = mlx_get_data_addr(buffer.img, &buffer.bits_per_pixel, &buffer.line_length, &buffer.endian);
	if (!load_res(&vars, &cmp))
		return (FAILURE);
	create_bg_layer(&buffer, &cmp, map);
	mlx_put_image_to_window(vars.mlx, vars.win, buffer.img, 0, 0);
	create_player_layer(&vars, &cmp, map);
	ctx->v = &vars;
	ctx->i = &buffer;
	ctx->m = map;
	ctx->c = &cmp;
	mlx_hook(vars.win, 2, 1L << 0, handle_press_key, ctx);
	mlx_loop(vars.mlx);
	return (SUCCESS);
}


/* map의 데이터 읽기 (arr 저장) (**메모리 free 필요 **)*/
int	read_map(char *argv, t_map	*map)
{
	int		fd;
	char	*map_data;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	map->cnt_row = cnt_map_row(argv); // map의 행 cnt (arr의 calloc 목적)
	map->arr = ft_calloc((map->cnt_row), sizeof(*(map->arr)));
	if (map->arr == NULL)
		return (FAILURE);
	i = 0;
	map->arr[i] = get_next_line(fd);
	while (map->arr[i++] != NULL)
	{
		map->arr[i] = get_next_line(fd);
		if (map->arr[i] == NULL)
			break ;
	}
	close(fd);
	map->cnt_col = cnt_map_col(map); // 위치 검토 필요
	return (SUCCESS);
}

void	init_all_struct(t_mlx_vars *vars, t_img *frame, t_comp *cmp)
{
	ft_bzero(vars, sizeof(t_mlx_vars));
	ft_bzero(frame, sizeof(t_img));
	ft_bzero(cmp, sizeof(t_comp));
	ft_bzero(cmp, sizeof(t_comp));
}

int	close_game(t_mlx_vars *vars)
{
	return (mlx_destroy_window(vars->mlx, vars->win), 0);
}
