/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:54:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/05 03:36:24 by sohuikim         ###   ########.fr       */
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
	int		cnt_p;
	int		cnt_c;
	int		cnt_e;
	int		visit_cnt_c;
	int		visit_cnt_e;
	int		p_x;
	int		p_y;
}	t_map;

int	read_map(char *argv, t_map	*map);
int	is_enclosed_by_walls(t_map *map);
int	is_row_filled(t_map *map);
int	is_column_filled(t_map *map);
int	cnt_map_column(t_map *map);
int	cnt_map_row(char *argv);

#endif