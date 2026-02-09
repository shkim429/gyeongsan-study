/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:25:44 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 15:24:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "valid_map.h"
#include "handle_frame.h"
#include "create_img_layer.h"
#include "load_res.h"
#include "setup_game_info.h"
#include "init_res.h"
#include "error.h"
#include "free_res.h"
#include "ft_libft.h"
#include "mlx.h"
#include <stdlib.h>

int	main(int argc, char *argv[])
{
	t_mlx		m_vars;
	t_map_info	map;
	t_comp		cmp;
	t_game_info	game;

	if (argc <= 1)
		return (print_error("invalid number of arguments", \
			"invalid number of arguments provided to program."), FAILURE);
	init_all_struct(&m_vars, &map, &cmp, &game);
	if (!read_map(argv[1], &map))
		return (FAILURE);
	if (!is_valid_game(&map))
		return (free_map_arr(map.arr), FAILURE);
	if (!render_map(&m_vars, &map, &cmp))
		return (free_map_arr(map.arr), FAILURE);
	setup_game_info(&game, &m_vars, &cmp, &map);
	play_game(&game);
	return (free_map_arr(map.arr), SUCCESS);
}

int	read_map(char *argv, t_map_info	*map)
{
	int		fd;
	int		i;

	if (is_dir(argv))
		return (print_error(argv, "the file path is invalid."), FAILURE);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (print_error(argv, "the file path is invalid."), \
		exit(STDERR_FILENO), FAILURE);
	map->cnt_row = cnt_map_row(argv);
	map->arr = ft_calloc((map->cnt_row + 1), sizeof(char *));
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
	map->cnt_col = cnt_map_col(map);
	return (SUCCESS);
}

int	render_map(t_mlx *m_vars, t_map_info *map, t_comp *cmp)
{
	m_vars->mlx = mlx_init();
	if (m_vars->mlx == NULL)
		return (FAILURE);
	init_win(m_vars, map);
	if (!load_res(m_vars, cmp))
		return (FAILURE);
	if (!create_bg_layer(m_vars, cmp, map))
		return (FAILURE);
	mlx_put_image_to_window(m_vars->mlx, m_vars->win, cmp->frame.img, 0, 0);
	create_player_layer(m_vars, cmp, map);
	return (SUCCESS);
}

void	play_game(t_game_info *game)
{
	mlx_hook(game->mlx->win, 2, 1L << 0, handle_press_key, game);
	mlx_hook(game->mlx->win, 17, 1L << 17, close_game, game);
	mlx_loop(game->mlx->mlx);
}

int	is_dir(char *file_path)
{
	char	*dir;

	dir = ft_strchr(file_path, '/');
	if (dir == NULL)
		return (SUCCESS);
	if (*(dir + 1) == '/' || *(dir + 1) == '\0')
		return (SUCCESS);
	return (FAILURE);
}
