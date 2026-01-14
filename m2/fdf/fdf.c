/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 03:08:58 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/14 14:30:38 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "ft_libft.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*min_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (FAILURE);
	min_ptr = mlx_new_window(mlx_ptr, 500, 500, "sohuikim's fdf");
	mlx_loop(mlx_ptr);
	return (SUCCESS);

}

int	run_fdf(void)
{
	
}
