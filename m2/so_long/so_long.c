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
#include "mlx.h"
#include "stdio.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		handle_exit_key(int keycode, t_vars *vars);
int	close_game(t_vars *vars);
int	handle_exit_mouse(t_vars *vars);

int	main(void)
{
	t_vars	vars;
	t_data	img;
	char	*relative_path;
	int		img_w;
	int		img_h;

	vars.mlx = mlx_init();
	relative_path = "test_img.xpm";
	vars.win = mlx_new_window(vars.mlx, 2000, 2000, "Hello world");
	img.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_w, &img_h);
	if (img.img == NULL)
		return (NULL);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);

	// img.img = mlx_new_image(vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, handle_exit_key, &vars);
	mlx_loop(vars.mlx);
	return (SUCCESS);
}

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
