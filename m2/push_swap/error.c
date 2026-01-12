/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 22:20:13 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/12 15:27:26 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	free_stack(t_list_node *stack);

void	free_resource(t_error_case error, t_stack *stacks, t_mem_res *var)
{
	if (error == ERROR_MALLOC)
	{
		if (var->num_arr == NULL)
			free_split(var->splitstr_arr);
		else
		{
			free_split(var->splitstr_arr);
			free_num_arr(var->num_arr);
			free_index_arr(var->index_arr);
			free_stack(&(stacks->a));
		}
	}
	else if (error == ERROR_NONE)
	{
		free_split(var->splitstr_arr);
		free_num_arr(var->num_arr);
		free_index_arr(var->index_arr);
		free_stack(&(stacks->a));
	}

}

void	free_stack(t_list_node *stack)
{
	t_node	*tmp;
	t_node	*current_node;

	current_node = stack->head;
	while (current_node)
	{
		tmp = current_node->next;
		free(current_node);
		current_node = tmp;
	}
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}

void	print_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
}

void	handle_error_case(t_error_case error, t_mem_res *var)
{
	print_error();
	free_split(var->splitstr_arr);
	if (error == ERROR_INT_BOUNDARY || error == ERROR_DUPLICATE_NUM)
		free_num_arr(var->num_arr);
	exit(EXIT_FAILURE);
}
