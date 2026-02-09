/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:43:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 14:17:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_frame.h"
#include "create_img_layer.h"
#include "free_res.h"
#include "mlx.h"
#include "ft_libft.h"

int	handle_player(t_game_info *game, int y, int x)
{
	if (game->map->arr[game->map->p_y + y][game->map->p_x + x] == '1')
		return (FAILURE);
	else if (game->map->arr[game->map->p_y + y][game->map->p_x + x] == 'C')
	{
		game->map->cnt_c--;
		game->map->arr[game->map->p_y + y][game->map->p_x + x] = '0';
		copy_tile(&game->cmp->frame, &game->cmp->gnd, game->cmp->gnd.img_h * \
		(game->map->p_y + y), game->cmp->gnd.img_w * (game->map->p_x + x));
	}
	else if (game->map->arr[game->map->p_y + y][game->map->p_x + x] == 'E')
	{
		if (game->map->cnt_c == 0)
		{
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
									game->cmp->frame.img, 0, 0);
			mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
game->cmp->player.img, (game->map->p_x + x) * 50, (game->map->p_y + y) * 50);
			return (close_game(game));
		}
	}
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
							game->cmp->frame.img, 0, 0);
	mlx_put_image_to_window(game->mlx->mlx, game->mlx->win, \
game->cmp->player.img, (game->map->p_x + x) * 50, (game->map->p_y + y) * 50);
	return (ft_printf("move count: %d\n", ++game->map->move_cnt), SUCCESS);
}

int	handle_press_key(int keycode, t_game_info *game)
{
	if (keycode == XK_ESC)
		return (close_game(game));
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

int	close_game(t_game_info *game)
{
	free_map_arr(game->map->arr);
	free_mlx(game);
	exit(EXIT_SUCCESS);
}
