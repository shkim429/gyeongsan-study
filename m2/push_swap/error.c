/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:20:13 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/14 01:33:58 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include <unistd.h>
#include <stdlib.h>

void	free_res(t_error_case error, t_stack *stack, t_mem_res *var)
{
	if (error == ERROR_MALLOC)
	{
		if (var->num_arr == NULL)
			free_split(var->splitstr_arr);
		else
		{
			free_split(var->splitstr_arr);
			free_num_arr(var->num_arr);
			free_rank_arr(var->index_arr);
			free_stack(&(stack->a));
		}
	}
	else if (error == ERROR_NONE)
	{
		free_split(var->splitstr_arr);
		free_num_arr(var->num_arr);
		free_rank_arr(var->index_arr);
		free_stack(&(stack->a));
	}
}

void	handle_error_case(t_error_case error, t_mem_res *var)
{
	(void) error;
	print_error();
	free_num_arr(var->num_arr);
	free_split(var->splitstr_arr);
	exit(EXIT_FAILURE);
}

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}
