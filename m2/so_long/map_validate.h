/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:54:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/22 15:54:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATE_H
# define MAP_VALIDATE_H

# define SUCCESS 1
# define FAILURE 0
# define CNT_FIRST_LAST_ROW 2

typedef struct s_map
{
	char	**arr;
	int		cnt_row;
	int		cnt_column;
}	t_map;

int	read_map(char *argv, t_map	*map);
int	is_enclosed_by_walls(t_map *map);
int	is_row_filled(t_map *map);
int	cnt_map_column(t_map *map);
int	cnt_map_row(char *argv);

#endif