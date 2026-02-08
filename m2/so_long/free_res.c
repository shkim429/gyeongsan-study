/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 01:53:20 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 21:53:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include "mlx.h"

void	free_map_arr(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
		free(map_arr[i++]);
	free(map_arr);
	map_arr = NULL;
}

void	destroy_img(t_game_info *game)
{
	mlx_destroy_image(game->mlx->mlx, game->cmp->frame.img);
	mlx_destroy_image(game->mlx->mlx, game->cmp->floor.img);
	mlx_destroy_image(game->mlx->mlx, game->cmp->wall.img);
	mlx_destroy_image(game->mlx->mlx, game->cmp->item.img);
	mlx_destroy_image(game->mlx->mlx, game->cmp->exit.img);
	mlx_destroy_image(game->mlx->mlx, game->cmp->player.img);
}

void	free_mlx(t_game_info *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx->mlx, game->mlx->win);
	mlx_destroy_display(game->mlx->mlx);
	free(game->mlx->mlx);
}
