/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 23:25:44 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 22:32:59 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "valid_map.h"
#include "load_res.h"
#include "handle_frame.h"
#include "create_img_layer.h"
#include "error.h"
#include "free_res.h"
#include "ft_libft.h"
#include "mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdlib.h>

int	is_file_path(char *file_path);

int	main(int argc, char *argv[])
{
	t_map_info	map;

	if (argc <= 1)
		return (print_error("a few argv", "a few"), FAILURE);
	ft_bzero(&map, sizeof(t_map_info));
	if (!read_map(argv[1], &map))
		return (FAILURE);
	if (!is_valid_game(&map))
		return (free_map_arr(map.arr), FAILURE);
	if (!render_map(&map))
		return (free_map_arr(map.arr), FAILURE);
	return (free_map_arr(map.arr), SUCCESS);
}

int	render_map(t_map_info *map)
{
	t_mlx		m_vars;
	t_comp		cmp;
	t_game_info	game;

	init_all_struct(&m_vars, &cmp, &game);
	m_vars.mlx = mlx_init();
	if (m_vars.mlx == NULL)
		return (FAILURE);
	init_win(&m_vars, map);
	if (!load_res(&m_vars, &cmp))
		return (FAILURE);
	if (!create_bg_layer(&m_vars, &cmp, map))
		return (FAILURE);
	mlx_put_image_to_window(m_vars.mlx, m_vars.win, cmp.frame.img, 0, 0);
	create_player_layer(&m_vars, &cmp, map);
	setup_game_info(&game, &m_vars, &cmp, map);
	mlx_hook(m_vars.win, 2, 1L << 0, handle_press_key, &game);
	mlx_hook(m_vars.win, DestroyNotify, StructureNotifyMask, click_x, &game);
	mlx_loop(m_vars.mlx);
	return (SUCCESS);
}

void	setup_game_info(t_game_info *game, t_mlx *m_vars, t_comp *cmp, \
						t_map_info *map)
{
	game->mlx = m_vars;
	game->cmp = cmp;
	game->map = map;
}

void	init_win(t_mlx *m_vars, t_map_info *map)
{
	int	tile_size;

	tile_size = 50;
	m_vars->win_x = tile_size * map->cnt_col;
	m_vars->win_y = tile_size * map->cnt_row;
	m_vars->win = mlx_new_window(m_vars->mlx, m_vars->win_x, m_vars->win_y, \
								"sohuikim");
}

int	read_map(char *argv, t_map_info	*map)
{
	int		fd;
	char	*map_data;
	int		i;

	if (!is_file_path(argv))
		return (FAILURE);
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (print_error(argv, "wrong path"), exit(STDERR_FILENO), FAILURE);
	map->cnt_row = cnt_map_row(argv);
	map->arr = ft_calloc((map->cnt_row + 1), sizeof(*(map->arr)));
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

int	is_file_path(char *file_path)
{
	char	*file;

	file = ft_strchr(file_path, '/');
	if (file == NULL)
		return (FAILURE);
	if (*(file + 1) == '/' || *(file + 1) == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int	load_res(const t_mlx *m_vars, t_comp *cmp)
{
	if (!load_floor_img(m_vars, cmp))
		return (FAILURE);
	if (!load_item_img(m_vars, cmp))
		return (FAILURE);
	if (!load_wall_img(m_vars, cmp))
		return (FAILURE);
	if (!load_exit_img(m_vars, cmp))
		return (FAILURE);
	if (!load_player_img(m_vars, cmp))
		return (FAILURE);
	return (SUCCESS);
}

void	init_all_struct(t_mlx *vars, t_comp *cmp, t_game_info *game)
{
	ft_bzero(vars, sizeof(t_mlx));
	ft_bzero(cmp, sizeof(t_comp));
	ft_bzero(game, sizeof(t_game_info));
}


