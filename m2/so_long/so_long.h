/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 04:52:35 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 22:14:07 by sohuikim         ###   ########.fr       */
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

# define XK_BUTTON_LEFT	1

typedef struct s_map_info
{
	char	**arr;
	int		cnt_row;
	int		cnt_col;
	int		cnt_p;
	int		cnt_c;
	int		cnt_e;
	int		visit_cnt_c;
	int		visit_cnt_e;
	int		p_x;
	int		p_y;
	int		move_cnt;
}	t_map_info;

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		img_w;
	int		img_h;
}	t_img_info;

typedef struct s_comp
{
	t_img_info	frame;
	t_img_info	floor;
	t_img_info	exit;
	t_img_info	item;
	t_img_info	player;
	t_img_info	wall;
}	t_comp;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		win_x;
	int		win_y;
}	t_mlx;

typedef struct s_game_info
{
	t_mlx		*mlx;
	t_map_info	*map;
	t_comp		*cmp;
}	t_game_info;

int	read_map(char *argv, t_map_info	*map);
int		render_map(t_map_info *map);
void	init_win(t_mlx *m_vars, t_map_info *map);
void	init_all_struct(t_mlx *vars, t_comp *cmp, t_game_info *game);
void	setup_game_info(t_game_info *game, t_mlx *m_vars, t_comp *cmp, \
						t_map_info *map);
void	init_win(t_mlx *m_vars, t_map_info *map);
int	load_res(const t_mlx *m_vars, t_comp *cmp);

#endif