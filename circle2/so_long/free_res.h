/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 02:27:22 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 18:47:28 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_RES_H
# define FREE_RES_H

# include "so_long.h"

void	free_map_arr(char **map_arr);
void	destroy_img(t_game_info *game);
void	free_mlx(t_game_info *game);

#endif