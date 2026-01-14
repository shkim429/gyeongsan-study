/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/15 05:25:30 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack_ops.h"
#include <stdlib.h>

int	run_sort(t_stack *stack, t_mem_res *var, t_sort_utils *sort_utils)
{
	if (var->cnt_input <= 5)
		run_insert_sort(stack, sort_utils, var->cnt_input);
	else
	{
		if (!rank_stack_data(var))
			return (FAILURE);
		binary_radix_sort(stack, var);
	}
	return (SUCCESS);
}

void	binary_radix_sort(t_stack *stack, t_mem_res *var)
{
	static int	bit;
	int			i;
	int			rank;

	while (!is_sorted_asc(stack->a.head))
	{
		i = 0;
		while (i < var->cnt_input)
		{
			rank = find_stack_data_rank(stack->a.head, var);
			if (((rank >> bit) & 1) == 0)
				push_ops(PUSH_B, stack);
			else
			{
				if (stack->a.size == 1)
					break ;
				rotate_ops(ROTATE_A, stack);
			}
			i++;
		}
		while (stack->b.size)
			push_ops(PUSH_A, stack);
		bit++;
	}
}

void	run_insert_sort(t_stack *stack, t_sort_utils *sort_utils, int a_size)
{
	sort_utils->min_value = find_min_value(&(stack->a));
	sort_utils->max_value = find_max_value(&(stack->a));
	while (1)
	{
		if ((stack->a.size == a_size) && is_sorted_asc(stack->a.head))
			return ;
		if (stack->a.head->data == sort_utils->max_value)
			rotate_ops(ROTATE_A, stack);
		if (stack->b.size == 0 && is_sorted_asc(stack->a.head))
			return ;
		if ((stack->b.size != 0) && is_sorted_des(stack->b.head) && \
			is_sorted_asc(stack->a.head))
		{
			while (stack->b.size)
				push_ops(PUSH_A, stack);
			return ;
		}
		insert_sort(stack, sort_utils);
	}
}

void	insert_sort(t_stack *stack, t_sort_utils *sort_utils)
{
	if (stack->a.head->data == sort_utils->min_value)
	{
		push_ops(PUSH_B, stack);
		sort_utils->min_value = find_min_value(&(stack->a));
	}
	if (stack->a.head->data > stack->a.head->next->data)
	{
		return (swap_ops(SWAP_A, stack));
		if (sort_utils->min_value == stack->a.head->data)
		{
			push_ops(PUSH_B, stack);
			sort_utils->min_value = find_min_value(&(stack->a));
		}
		else
			rotate_ops(ROTATE_A, stack);
		return ;
	}
	else
		rotate_ops(ROTATE_A, stack);
	return ;
}
