/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exit_path_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:04:30 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 03:55:43 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "valid_map.h"
#include "stdbool.h"

/* plyaer 위치 찾기 */
void	get_plyaer_pos(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->cnt_row)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == 'P')
			{
				map->p_row = row;
				map->p_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

/* exit_path 탐색 */
void	dfs(t_map *map, int *visit_arr, int row, int col)
{
	if (row < 0 || row >= map->cnt_row || col < 0 || col >= map->cnt_col)
		return ;
	if (visit_arr[(row * map->cnt_col) + col] == TRUE || map->arr[row][col] == '1')
		return ;
	if (map->arr[row][col] == 'C')
		map->visit_cnt_c++;
	if (map->arr[row][col] == 'E')
		map->visit_cnt_e++;
	visit_arr[(row * map->cnt_col) + col] = TRUE;
	dfs(map, visit_arr, row - 1, col);
	dfs(map, visit_arr, row, col + 1);
	dfs(map, visit_arr, row + 1, col);
	dfs(map, visit_arr, row, col - 1);
}
