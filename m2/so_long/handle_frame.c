/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:43:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 22:41:26 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_frame.h"
#include "create_img_layer.h"
#include "free_res.h"
#include "ft_libft.h"
#include "mlx.h"

int	handle_player(t_game_info *game, int row, int col)
{
	if (game->map->arr[game->map->p_y + row][game->map->p_x + col] == '1')
		return (FAILURE);
	else if (game->map->arr[game->map->p_y + row][game->map->p_x + col] == 'C')
	{
		game->map->cnt_c--;
		game->map->arr[game->map->p_y + row][game->map->p_x + col] = '0';
		copy_tile(&game->cmp->frame, &game->cmp->floor, game->cmp->floor.img_h * \
		(game->map->p_y + row), game->cmp->floor.img_w * (game->map->p_x + col));
	}
	else if (game->map->arr[game->map->p_y + row][game->map->p_x + col] == 'E')
	{
		if (game->map->cnt_c == 0)
		{
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
									game->cmp->frame.img, 0, 0);
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
				game->cmp->player.img, (game->map->p_x + col) * 50, \
				(game->map->p_y + row) * 50);
			return (close_game(game->mlx->mlx, game));
		}
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->cmp->frame.img, 0, 0);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, game->cmp->player.img, \
		(game->map->p_x + col) * 50, (game->map->p_y + row) * 50);
	return (ft_printf("move count: %d\n", ++game->map->move_cnt), SUCCESS);
}

int	handle_press_key(int keycode, t_game_info *game)
{
	if (keycode == XK_ESC)
		return (close_game(game->mlx, game));
	else if (keycode == XK_UP)
	{
		if (handle_player(game, -1, 0))
			game->map->p_y--;
	}
	else if (keycode == XK_DOWN)
	{
		if (handle_player(game, +1, 0))
			game->map->p_y++;
	}
	else if (keycode == XK_LEFT)
	{
		if (handle_player(game, 0, -1))
			game->map->p_x--;
	}
	else if (keycode == XK_RIGHT)
	{
		if (handle_player(game, 0, +1))
			game->map->p_x++;
	}
	return (SUCCESS);
}
#include <stdio.h>
int	click_x(t_game_info *game)
{
	int keycode = 0;
	
	// printf("%d\n", keycode);
	if (keycode == XK_BUTTON_LEFT)
		return (close_game(game->mlx, game));
	return (SUCCESS);
}

int	close_game(t_mlx *vars, t_game_info *game)
{
	free_map_arr(game->map->arr);
	free_mlx(game);
	exit(EXIT_SUCCESS);
}

// int	click_x(t_game_info *game)
// {
// 	free_map_arr(game->map->arr);
// 	free_mlx(game);
// 	exit(EXIT_SUCCESS);
// }
