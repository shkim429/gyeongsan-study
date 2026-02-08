/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:32:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/08 20:17:39 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "load_res.h"
#include "ft_libft.h"
#include "mlx.h"
#include <stdlib.h>

int	load_floor_img(const t_mlx *vars, t_comp *cmp)
{
	cmp->floor.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/gnd.xpm", &cmp->floor.img_w, &cmp->floor.img_h);
	if (cmp->floor.img == NULL)
		return (FAILURE);
	cmp->floor.addr = mlx_get_data_addr(cmp->floor.img, \
&cmp->floor.bpp, &cmp->floor.line_len, &cmp->floor.endian);
	return (SUCCESS);
}

int	load_wall_img(const t_mlx *vars, t_comp *cmp)
{
	cmp->wall.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/wall.xpm", &cmp->wall.img_w, &cmp->wall.img_h);
	if (cmp->wall.img == NULL)
		return (FAILURE);
	cmp->wall.addr = mlx_get_data_addr(cmp->wall.img, \
	&cmp->wall.bpp, &cmp->wall.line_len, \
	&cmp->wall.endian);
	return (SUCCESS);
}

int	load_exit_img(const t_mlx *vars, t_comp *cmp)
{
	cmp->exit.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/exit.xpm", &cmp->exit.img_w, &cmp->exit.img_h);
	if (cmp->exit.img == NULL)
		return (FAILURE);
	cmp->exit.addr = mlx_get_data_addr(cmp->exit.img, \
&cmp->exit.bpp, &cmp->exit.line_len, &cmp->exit.endian);
	return (SUCCESS);
}

int	load_player_img(const t_mlx *vars, t_comp *cmp)
{
	cmp->player.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/player.xpm", &cmp->player.img_w, &cmp->player.img_h);
	if (cmp->player.img == NULL)
		return (FAILURE);
	cmp->player.addr = mlx_get_data_addr(cmp->player.img, \
&cmp->player.bpp, &cmp->player.line_len, &cmp->player.endian);
	return (SUCCESS);
}

int	load_item_img(const t_mlx *vars, t_comp *cmp)
{
	cmp->item.img = mlx_xpm_file_to_image(vars->mlx, \
"./textures/item.xpm", &cmp->item.img_w, &cmp->item.img_h);
	if (cmp->item.img == NULL)
		return (FAILURE);
	cmp->item.addr = mlx_get_data_addr(cmp->item.img, \
	&cmp->item.bpp, &cmp->item.line_len, &cmp->item.endian);
	return (SUCCESS);
}
