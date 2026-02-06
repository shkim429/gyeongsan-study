/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:44:34 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:26:19 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"
#include "ft_libft.h"

int	is_valid_game(t_map *map)
{
	if (!is_enclosed_by_walls(map))
		return (FAILURE);
	if (!is_valid_cnt_spr(map))
		return (FAILURE);
	if (!is_valid_exit_path(map))
	return (SUCCESS);
}

/* 벽 잘 닫혀 있는지 */
int	is_enclosed_by_walls(t_map *map)
{
	if (!is_row_filled(map))
		return (FAILURE);
	if (!is_col_filled(map))
		return (FAILURE);
	return (SUCCESS);
}

/* 요소가 적절히 있는지 */
int	is_valid_cnt_spr(t_map *map)
{
	int	row;
	int	col;

	map->cnt_c = 0; // 3개 삭제 예정
	map->cnt_p = 0;
	map->cnt_e = 0;
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
			col++;
		}
		row++;
	}
	if (map->cnt_c <= 0 || map->cnt_p <= 0 || map->cnt_p > 1 || \
map->cnt_e <= 0 || map->cnt_e > 1)
		return (FAILURE);
	return (SUCCESS);
}

/* 탈출 경로가 있는지 */
int	is_valid_exit_path(t_map *map)
{
	int	*visit_arr;

	map->visit_cnt_c = 0;
	map->visit_cnt_e = 0;
	visit_arr = malloc((map->cnt_row * map->cnt_col) * sizeof(*(visit_arr)));
	if (visit_arr == NULL)
		return (FAILURE);
	ft_memset(visit_arr, FALSE, map->cnt_row * map->cnt_col);
	get_plyaer_pos(map);
	dfs(map, visit_arr, map->p_row, map->p_col);
	if (map->visit_cnt_c != map->cnt_c || map->visit_cnt_e != map->cnt_e)
		return (FAILURE);
	return (SUCCESS);
}
