/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_exit_path_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:04:30 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 20:22:45 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "valid_map.h"
#include "stdbool.h"

void	get_plyaer_pos(t_map_info *map)
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
				map->p_y = row;
				map->p_x = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

void	dfs(t_map_info *map, int *visit_arr, int row, int col)
{
	if (row < 0 || row >= map->cnt_row || col < 0 || col >= map->cnt_col)
		return ;
	if (visit_arr[(row * map->cnt_col) + col] == TRUE)
		return ;
	if (map->arr[row][col] == '1')
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
