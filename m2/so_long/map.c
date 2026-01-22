/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:44:34 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/22 14:11:20 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "ft_libft.h"
#include <stdio.h>

/*
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			line = get_next_line(fd);
			pritnf("%s", line);
		}
	}
}
*/

/* map의 데이터 읽기 (row_arr 저장) (**메모리 free 필요 **)*/
int	read_map(char *argv, t_map	*map)
{
	int		fd;
	char	*map_data;
	int		i;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (FAILURE);
	map->cnt_row = cnt_map_row(argv); // map의 행 cnt (row_arr의 calloc 목적)
	map->row_arr = ft_calloc((map->cnt_row) + 1, sizeof(*(map->row_arr)));
	if (map->row_arr == NULL)
		return (FAILURE);
	i = 0;
	map->row_arr[i] = get_next_line(fd);
	while (map->row_arr[i++] != NULL)
	{
		map->row_arr[i] = get_next_line(fd);
		if (map->row_arr[i] == NULL)
			break ;
	}
	close(fd);
	return (SUCCESS);
}

int	is_enclosed_by_walls(t_map *map)
{
	int cnt = cnt_map_longest_row(map);
	printf("%d\n", cnt);

	/*
	if (!is_row_filled(map))
		return (FAILURE);
	return (SUCCESS);
	*/
}

int	is_row_filled(t_map *map)
{
	int	last_row;
	int	i;
	int	j;
	int	cnt_first_last_row;

	last_row = map->cnt_row - 1;
	cnt_first_last_row = 2;
	map->cnt_column = cnt_map_column(map);
	i = 0;
	while (cnt_first_last_row--)
	{
		j = 0;
		while (j < map->cnt_column)
		{
			if (map->row_arr[i][j] == '1')
				j++;
			else
				return (FAILURE); // 할당된 메모리 free 필요
		}
		if (map->row_arr[i][j] != '\n') // len_first_row < len_last_row인 경우
			return (FAILURE);
		i = last_row;
	}
	return (SUCCESS);
}

int	cnt_map_longest_row(t_map *map)
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
		while (map->row_arr[i][j] != '\n' && map->row_arr[i][j] != '\0')
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

int	cnt_map_column(t_map *map)
{
	int	column;

	column = 0;
	while (map->row_arr[0][column] != '\n')
		column++;
	return (column);
}


// /* 가장 긴 열의 문자 수 세기 */
// cnt_map_lonest_column(t_map *map)
// {
// 	int	column;

// 	column = 0;
// 	while ()
// }
