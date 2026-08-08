/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img_layer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 04:16:05 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 10:54:07 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_IMG_LAYER_H
# define CREATE_IMG_LAYER_H

# include "so_long.h"

int		create_bg_layer(t_mlx *m_vars, t_comp *cmp, t_map_info *map);
void	create_terrian_layer(t_img_info *dst, t_comp *cmp, t_map_info *map);
void	create_obj_layer(t_img_info *dst, t_comp *cmp, t_map_info *map);
void	create_player_layer(t_mlx *m_vars, t_comp *cmp, t_map_info *map);
void	copy_tile(t_img_info *dst, t_img_info *src, int row, int col);

#endif