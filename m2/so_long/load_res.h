/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/09 07:53:28 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_RES_H
# define LOAD_RES_H

# include "so_long.h"

int		load_res(t_mlx *vars, t_comp *cmp);
int	    load_terrian_img(t_mlx *vars, t_comp *cmp);
int		load_exit_img(t_mlx *vars, t_comp *cmp);
int		load_player_img(t_mlx *vars, t_comp *cmp);
int		load_item_img(t_mlx *vars, t_comp *cmp);

#endif