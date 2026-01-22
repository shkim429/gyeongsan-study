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
#include "ft_libft.h"
#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_exit_key(int keycode, t_vars *vars);
int	close_game(t_vars *vars);
int	handle_exit_mouse(t_vars *vars);

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
	return (SUCCESS);
}

int	render_map(t_map *map)
{
	
}

/*
int	main(int argc, char *argv[])
{
	tile_size = 50;

	vars.mlx = mlx_init();
	relative_path = "./textures/road.xpm";
	vars.win = mlx_new_window(vars.mlx, 1080, 1080, "Hello world");
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_w, &img_h);
	if (img.img == NULL)
		return (0);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	// img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, handle_exit_key, &vars);
	mlx_loop(vars.mlx);
	return (SUCCESS);
*/

int	handle_exit_key(int keycode, t_vars *vars)
{
	if (keycode == XK_ESC)
		close_game(vars);
	return (0);
}

int	close_game(t_vars *vars)
{
	return (mlx_destroy_window(vars->mlx, vars->win), 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
