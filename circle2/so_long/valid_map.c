/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:44:34 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 14:38:50 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "valid_map.h"
#include "ft_libft.h"
#include "error.h"

int	is_valid_game(t_map_info *map)
{
	if (!is_enclosed_by_walls(map))
		return (print_error("invalid map format", \
				"map is not enclosed by walls."), FAILURE);
	if (!is_valid_cnt_spr(map))
		return (print_error("invalid map format", \
				"map element count or format is invalid."), FAILURE);
	if (!is_valid_exit_path(map))
		return (print_error("invalid map format", \
				"no valid path to exit."), FAILURE);
	return (SUCCESS);
}

int	is_enclosed_by_walls(t_map_info *map)
{
	if (!is_row_filled(map))
		return (FAILURE);
	if (!is_col_filled(map))
		return (FAILURE);
	return (SUCCESS);
}

int	is_valid_cnt_spr(t_map_info *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == 'C')
				map->cnt_c++;
			else if (map->arr[row][col] == 'E')
				map->cnt_e++;
			else if (map->arr[row][col] == 'P')
				map->cnt_p++;
			else if (map->arr[row][col] != '0' && map->arr[row][col] != '1')
				return (FAILURE);
			col++;
		}
		row++;
	}
	if (map->cnt_c <= 0 || map->cnt_p <= 0 || map->cnt_p > 1 || \
map->cnt_e <= 0 || map->cnt_e > 1)
		return (FAILURE);
	return (SUCCESS);
}

int	is_valid_exit_path(t_map_info *map)
{
	int	*visit_arr;

	map->visit_cnt_c = 0;
	map->visit_cnt_e = 0;
	visit_arr = malloc((map->cnt_row * map->cnt_col) * sizeof(*(visit_arr)));
	if (visit_arr == NULL)
		return (FAILURE);
	ft_memset(visit_arr, FALSE, \
		(map->cnt_row * map->cnt_col) * sizeof(*(visit_arr)));
	get_plyaer_pos(map);
	dfs(map, visit_arr, map->p_y, map->p_x);
	if (map->visit_cnt_c != map->cnt_c || map->visit_cnt_e != map->cnt_e)
		return (free(visit_arr), FAILURE);
	return (free(visit_arr), SUCCESS);
}
