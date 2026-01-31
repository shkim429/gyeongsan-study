/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:52:35 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/29 15:30:36 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FAILURE 0
# define SUCCESS 1

# define XK_ESC 	0xff1b
# define XK_UP		0xff52
# define XK_DOWN	0xff54
# define XK_LEFT	0xff51
# define XK_RIGHT	0xff53
# define XK_W		0x0057
# define XK_S		0x0053
# define XK_D		0x0044
# define XK_A		0x0041
# define XK_BUTTON_LEFT	0xfee9

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img;

typedef struct s_mlx_vars // s_mlx_ctx로 변경하기
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
}	t_mlx_vars;

/*
typedef struct s_win_size
{
	int	win_x;
	int	win_y;
}	t_win_size;
*/

#endif