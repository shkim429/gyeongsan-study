/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_frame.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:40:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 15:59:23 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FRAME_H
# define HANDLE_FRAME_H

#include "so_long.h"

int	handle_player(int keycode, t_ctx *ctx);
int	move_player(t_ctx *ctx);
int	handle_press_key(int keycode, t_ctx *ctx);

#endif