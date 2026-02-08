/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_frame.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:40:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 22:36:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FRAME_H
# define HANDLE_FRAME_H

# include "so_long.h"

int	handle_player(t_game_info *game, int row, int col);
int	handle_press_key(int keycode, t_game_info *game);
int	click_x(t_game_info *game);
int	close_game(t_mlx *vars, t_game_info *game);
// int	click_x(t_game_info *game);

#endif