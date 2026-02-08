/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 23:54:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 19:58:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_H
# define VALID_MAP_H

# include "so_long.h"

# define FALSE 0
# define TRUE 1

int		is_valid_game(t_map_info *map);
int		is_enclosed_by_walls(t_map_info *map);
int		is_valid_cnt_spr(t_map_info *map);
int		is_valid_exit_path(t_map_info *map);
int		is_col_filled(t_map_info *map);
int		is_row_filled(t_map_info *map);
int		cnt_map_row(char *argv);
int		cnt_map_col(t_map_info *map);
void	get_plyaer_pos(t_map_info *map);
void	dfs(t_map_info *map, int *visit_arr, int row, int col);

#endif
