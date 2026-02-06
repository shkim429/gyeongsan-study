/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:52:35 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 04:28:34 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define FAILURE 0
# define SUCCESS 1
# define NOT_VISITED 0
# define VISITED 1

# define XK_ESC 	0xff1b
# define XK_UP		0xff52
# define XK_DOWN	0xff54
# define XK_LEFT	0xff51
# define XK_RIGHT	0xff53
# define XK_BUTTON_LEFT	0xfee9

typedef struct s_map
{
	char	**arr;
	int		cnt_row;
	int		cnt_col;
	int		cnt_p;
	int		cnt_c;
	int		cnt_e;
	int		visit_cnt_c;
	int		visit_cnt_e;
	int		p_row;
	int		p_col;
}	t_map;

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

typedef struct s_tileset
{
	t_img	floor;
	t_img	item;
	t_img	car_rd_r;
	t_img	car_gn_r;
	t_img	car_yl_r;
}	t_tileset;

typedef struct s_sprites
{

	t_img	exit;
	t_img	item;
	t_img	p_f;
	t_img	p_b;
	t_img	p_l;
	t_img	p_run_l;
	t_img	p_r;
	t_img	p_run_r;
}	t_sprites;

typedef struct s_mlx_vars // s_mlx_ctx로 변경하기
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
}	t_mlx_vars;

typedef struct s_ctx
{
	t_mlx_vars	*v;
	t_map		*m;
	t_img		*i;
	t_sprites	*s;
	t_tileset	*t;
}	t_ctx;

int	read_map(char *argv, t_map	*map);
int	render_map(t_map *map, t_ctx *ctx);
int	close_game(t_mlx_vars *vars);
#endif