/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 19:55:33 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_RES_H
# define LOAD_RES_H

# include "so_long.h"

int		load_res(const t_mlx *vars, t_comp *cmp);
int		load_floor_img(const t_mlx *vars, t_comp *cmp);
int		load_wall_img(const t_mlx *vars, t_comp *cmp);
int		load_exit_img(const t_mlx *vars, t_comp *cmp);
int		load_player_img(const t_mlx *vars, t_comp *cmp);
int		load_item_img(const t_mlx *vars, t_comp *cmp);

#endif