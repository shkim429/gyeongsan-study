/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 03:43:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 16:07:56 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_frame.h"
#include "create_img_layer.h"
#include "mlx.h"

int	handle_player(int keycode, t_ctx *ctx)
{
	if (ctx->m->arr[ctx->m->p_row][ctx->m->p_col] == '1')
		return (FAILURE);
	else if (ctx->m->arr[ctx->m->p_row][ctx->m->p_col] == 'C')
	{
		ctx->m->cnt_c--;
		copy_tile(ctx->i, &ctx->c->floor.img, ctx->c->floor.img_h * ctx->m->p_row, ctx->c->floor.img_w * ctx->m->p_col);
	}
	else if (ctx->m->arr[ctx->m->p_row][ctx->m->p_col] == 'E')
	{
		if (ctx->m->cnt_c == 0)
		{
			mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50);
			// return(mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50));
			mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50);
			return (close_game(ctx->v->mlx));
			
		}
	}
	mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->i->img, 0, 0);
	mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50);
    return (SUCCESS);
}

int	move_player(t_ctx *ctx)
{
	if (ctx->m->arr[ctx->m->p_row][ctx->m->p_col] == '1')
		return (FAILURE);
	else if(ctx->m->arr[ctx->m->p_row][ctx->m->p_col] == 'C')
		ctx->m->cnt_c--;
	else if(ctx->m->arr[ctx->m->p_row][ctx->m->p_col] == 'E')
	{
		if (ctx->m->cnt_c == 0)
		{
			mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50);
			return(mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50));
			// game_exit 되어야 함
		}
	}
	mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->i->img, 0, 0);
	mlx_put_image_to_window(ctx->v->mlx, ctx->v->win, ctx->c->p_r.img, ctx->m->p_col * 50, ctx->m->p_row * 50);
	return (SUCCESS);
}
int	handle_press_key(int keycode, t_ctx *ctx)
{
	if (keycode == XK_ESC)
		return (close_game(ctx->v));
	else if (keycode == XK_UP)
	{
		ctx->m->p_row--;
		if(!handle_player(keycode, ctx))
			ctx->m->p_row++;
	}
	else if (keycode == XK_DOWN)
	{
		ctx->m->p_row++;
		if(!handle_player(keycode, ctx))
			ctx->m->p_row--;
	}
	else if (keycode == XK_LEFT)
	{
		ctx->m->p_col--;
		if(!handle_player(keycode, ctx))
			ctx->m->p_col++;
	}
	else if (keycode == XK_RIGHT)
	{
		ctx->m->p_col++;
		if(!handle_player(keycode, ctx))
			ctx->m->p_col--;
	}
}

int	handle_exit_key(int keycode, t_mlx_vars *vars)
{
	if (keycode == XK_ESC)
		close_game(vars);
	return (0);
}