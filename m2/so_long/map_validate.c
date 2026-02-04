/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:44:34 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/05 00:03:24 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validate.h"
#include "ft_libft.h"
#include <stdio.h>

/* map의 데이터 읽기 (arr 저장) (**메모리 free 필요 **)*/
int	read_map(char *argv, t_map	*map)
{
	int		fd;
	char	*map_data;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	map->cnt_row = cnt_map_row(argv); // map의 행 cnt (arr의 calloc 목적)
	map->arr = ft_calloc((map->cnt_row), sizeof(*(map->arr)));
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
	map->cnt_column = cnt_map_column(map); // 위치 검토 필요
	return (SUCCESS);
}

int	is_enclosed_by_walls(t_map *map)
{
	if (!is_row_filled(map))
		return (FAILURE);
	if (!is_column_filled(map))
		return (FAILURE);
	return (SUCCESS);
}

/* 열의 엣지 데이터 = 1(wall) 확인 */
int	is_column_filled(t_map *map)
{
	int	row;
	int	column;
	int	last_column;
	int	cnt_first_last_column;

	last_column = map->cnt_column - 1;
	cnt_first_last_column = 2;
	column = 0;
	while (cnt_first_last_column--)
	{
		row = 0;
		while (row < map->cnt_row)
		{
			if (map->arr[row][column] == '1')
				row++;
			else
				return (FAILURE); // 할당된 메모리 free 필요
		}
		column = last_column;
	}
	return (SUCCESS);
}

/* 행의 엣지 데이터 = 1(wall) 확인 */
int	is_row_filled(t_map *map)
{
	int	row;
	int	column;
	int	last_row;
	int	cnt_first_last_row;

	last_row = map->cnt_row - 1;
	cnt_first_last_row = 2;
	row = 0;
	while (cnt_first_last_row--)
	{
		column = 0;
		while (column < map->cnt_column)
		{
			if (map->arr[row][column] == '1')
				column++;
			else
				return (FAILURE); // 할당된 메모리 free 필요
		}
		if (map->arr[row][column] != '\n') // len_first_row < len_last_row인 경우
			return (FAILURE);
		row = last_row;
	}
	return (SUCCESS);
}

/* 맵의 열 수 세기 */
int	cnt_map_column(t_map *map)
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
