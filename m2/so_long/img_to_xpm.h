/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_xpm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:35:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/31 03:09:35 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_TO_XPM_H
# define IMG_TO_XPM_H

typedef struct s_tileset
{
	t_img	road;
	t_img	red_car_fornt;
	t_img	red_car_left;
	t_img	green_car_fornt;
	t_img	green_car_left;
	t_img	blue_car_fornt;
	t_img	blue_car_left;
}	t_tileset;

typedef struct s_sprites
{
	t_img	item;
	t_img	exit;
	t_img	player_front;
	t_img	player_back;
	t_img	player_left;
	t_img	player_left_run;
	t_img	player_right;
	t_img	player_right_run;
}	t_sprites;


/* path 구조체 삭제 검토 필요(없어도 될 것 같음) */
typedef struct s_img_path
{
	char	*road_path;
	char	*sweet_potato_path;
	char	*exit_path;
	char	*red_car_fornt_path;
	char	*red_car_left_path;
	char	*green_car_fornt_path;
	char	*green_car_left_path;
	char	*blue_car_fornt_path;
	char	*blue_car_left_path;
	char	*player_front_path;
	char	*player_back_path;
	char	*player_left_path;
	char	*player_left_run_path;
	char	*player_right_path;
	char	*player_right_run_path;

}	t_img_path;

int	create_bg_layer(t_mlx_vars *vars, t_img *frame_buffer, t_tileset *tileset);
#endif