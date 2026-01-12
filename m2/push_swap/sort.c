/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:24:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"
#include "stack_ops.h"
#include <stdlib.h>

int	run_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils)
{
	if (var->cnt_input <= 5)
		insert_sort_controller(stacks, sort_utils);
	else
	{
		if (!rank_stack_data(var))
			return (FAILURE);
		radix_sort(stacks, var, sort_utils);
	}
	return (SUCCESS);
}

void	radix_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils)
{
	int		bit;
	int		i;
	int		rank;

	bit = 0;
	while (bit < var->cnt_input)
	{
		i = 0;
		while (i < var->cnt_input)
		{
			rank = find_stack_data_rank(stacks->a.head, var);
			if (((rank >> bit) & 1) == 0)
				push_ops(PUSH_B, stacks);
			else
			{
				if (stacks->a.size == 1)
					break ;
				rotate_ops(ROTATE_A, stacks);
				if (stacks->b.size == 0 && is_sorted_asc(stacks->a.head))
					return ;
			}
			i++;
		}
		while (stacks->b.size)
			push_ops(PUSH_A, stacks);
		bit++;
	}
}

void	insert_sort_controller(t_stack *stacks, t_sort_utils *sort_utils)
{
	int	stack_a_size;
	int	i;

	stack_a_size = stacks->a.size;
	sort_utils->key = stacks->a.head;
	sort_utils->min_value = find_min_value(&(stacks->a));
	sort_utils->max_value = find_max_value(&(stacks->a));
	while (1)
	{
		i = 0;
		if ((stacks->a.size == stack_a_size) && is_sorted_asc(stacks->a.head))
			return ;
		if (sort_utils->key->data == sort_utils->max_value)
		{
			if (is_sorted_des(stacks->a.head))
				rotate_ops(ROTATE_A, stacks);
			else
				rotate_ops(ROTATE_A, stacks);
		}
		sort_utils->key = stacks->a.head;
		if ((stacks->b.size != 0) && is_sorted_des(stacks->b.head) && is_sorted_asc(stacks->a.head))
		{
			while (stacks->b.size)
				push_ops(PUSH_A, stacks);
			return ;
		}
		insert_sort(stacks, sort_utils);
	}
}

void	insert_sort(t_stack *stacks, t_sort_utils *sort_utils)
{
	if (sort_utils->key->data == sort_utils->min_value)
	{
		push_ops(PUSH_B, stacks);
		sort_utils->key = stacks->a.head;
		sort_utils->min_value = find_min_value(&(stacks->a));
	}
	if (sort_utils->key->data > sort_utils->key->next->data)
	{
		swap_ops(SWAP_A, stacks);
		sort_utils->key = stacks->a.head;
		return ;
		if (sort_utils->key->next == NULL)
			return ;
		if (sort_utils->min_value == stacks->a.head->data)
		{
			push_ops(PUSH_B, stacks);
			sort_utils->min_value = find_min_value(&(stacks->a));
		}
		else
			rotate_ops(ROTATE_A, stacks);
		sort_utils->key = stacks->a.head;
		return ;
	}
	else
		rotate_ops(ROTATE_A, stacks);
	sort_utils->key = stacks->a.head;
	return ;
}






