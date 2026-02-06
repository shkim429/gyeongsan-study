/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:23:51 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:44:38 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"
#include <stdlib.h>
#include <fcntl.h>
#include "ft_libft.h"

/* 열의 엣지 데이터 = 1(wall) 확인 */
int	is_col_filled(t_map *map)
{
	int	row;
	int	col;
	int	i;

	col = 0;
	i = 0;
	while (i < 2) 
	{
		row = 0;
		while (row < map->cnt_row)
		{
			if (map->arr[row][col] == '1')
				row++;
			else
				return (FAILURE); // 할당된 메모리 free 필요
		}
		col = map->cnt_col - 1;
		i++;
	}
	return (SUCCESS);
}

/* 행의 엣지 데이터 = 1(wall) 확인 */
int	is_row_filled(t_map *map)
{
	int	row;
	int	col;
	int	i;

	row = 0;
	i = 0;
	while (i < 2)
	{
		col = 0;
		while (col < map->cnt_col)
		{
			if (map->arr[row][col] == '1')
				col++;
			else
				return (FAILURE); // 할당된 메모리 free 필요
		}
		if (map->arr[row][col] != '\n') // len_first_row < len_last_row인 경우
			return (FAILURE);
		row = map->cnt_row - 1;
		i++;
	}
	return (SUCCESS);
}

/* 맵의 행 수 세기 */
int	cnt_map_row(char *argv)
{
	int		fd;
	char	*line;
	int		cnt_map_row;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	cnt_map_row = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		cnt_map_row++;
		free(line);
		if (line == NULL)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	return (cnt_map_row);
}

/* 맵의 열 수 세기 */
int	cnt_map_col(t_map *map)
{
	int	i;
	int	j;
	int	cnt_longest_row;

	i = 0;
	j = 0;
	cnt_longest_row = 0;
	while (i < map->cnt_row)
	{
		j = 0;
		while (map->arr[i][j] != '\n' && map->arr[i][j] != '\0')
			j++;
		if (cnt_longest_row < j)
			cnt_longest_row = j;
		i++;
	}
	return (cnt_longest_row);
}