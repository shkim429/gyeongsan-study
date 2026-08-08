/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game_info.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 07:50:57 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 07:51:56 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_GAME_INFO_H
# define SETUP_GAME_INFO_H

# include "so_long.h"

void	setup_game_info(t_game_info *game, t_mlx *m_vars, t_comp *cmp, \
						t_map_info *map);
#endif