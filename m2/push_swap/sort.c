/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/11 06:26:20 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_node	*find_midnode_pos(t_list_node *stack_a);
int		max_bit_len(long num);
int		is_sorted_asc(t_list_node *stack);
int		is_sorted_des(t_list_node *stack_a);
void	sort_asc(t_stack *stacks);

/*
void	quick_sort(t_list_node *stack_a, t_list_node *stack_b)
{
	t_node	*pivot;
	t_node	*cur_node;

	pivot = find_midnode_pos(&stack_a);
	cur_node = stack_a->head;
	while (cur_node != NULL)
	{
		if (cur_node->data < pivot)
			push_node(&stack_a, &stack_b);
		cur_node = cur_node->next;

	}
}
*/

/*
t_node	*find_midnode_pos(t_list_node *stack_a)
{
	t_node	*mid_node;
	int		mid_idx;
	int		cnt;

	mid_idx = (stack_a->size) / 2;
	mid_node = stack_a->head;
	cnt = 0;
	while (cnt < mid_idx)
	{
		mid_node = mid_node->next;
		cnt++;
	}
	return (mid_node);
}
*/

int	find_max_value(t_list_node *stack)
{
	t_node	*cur_node;
	long	max_value;
	int		i;

	cur_node = stack->head;
	max_value = cur_node->data;
	i = 0;
	while (++i < stack->size)
	{
		cur_node = cur_node->next;
		if (max_value < cur_node->data)
			max_value = cur_node->data;
	}
	return (max_value);
}

void	sort(t_stack *stacks, int stack_size)
{
	if (stacks->b.size == 0 && is_sorted_des(&(stacks->a)))
		return (sort_asc(stacks));
	binary_radix_sort(stacks, stack_size);
}

void	sort_asc(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->a.size)
	{
		rotate_operations(ROTATE_A, stacks);
		i++;
	}
}
void	binary_radix_sort(t_stack *stacks, int stack_size)
{
	int		max_value;
	int		bit_len;
	int		bit;
	int		i;

	max_value = find_max_value(&(stacks->a));
	bit_len = max_bit_len(max_value);
	while (bit < bit_len)
	{
		i = 0;
		while (i < stack_size)
		{
			if (((stacks->a.head->data >> bit) & 1) == 0)
			{
				push_operations(PUSH_B, stacks);
			}
			else
			{
				rotate_operations(ROTATE_A, stacks);
				if (stacks->b.size == 0 && is_sorted_asc(&(stacks->a)))
					return ;
			}
			i++;
		}
		while (stacks->b.size)
			push_operations(PUSH_A, stacks);
		bit++;
	}
}

int	is_sorted_asc(t_list_node *stack)
{
	t_node	*cur_node;

	cur_node = stack->head;
	while (cur_node->next != NULL)
	{
		if (cur_node->data > cur_node->next->data)
		{
			return (0); // not sorted
		}
		cur_node = cur_node->next;
	}
	return (1);
}

int	is_sorted_des(t_list_node *stack)
{
	t_node	*cur_node;

	cur_node = stack->head;
	while (cur_node->next != NULL)
	{
		if (cur_node->data < cur_node->next->data)
			return (0); // not sorted
		cur_node = cur_node->next;
	}
	return (1);
}

/*
void	binary_radix_sort(t_malloc_resource *var, t_stack *stack)
{
	int	max_value;
	int	bit_len;
	int	bit;
	int	i;

	max_value = find_max_value();
	bit_len = max_bit_len(max_value);
	bit = 0;
	i = 0;
	while (bit < bit_len)
	{
		while (i < var->cnt_input)
		{
			if ((var->num_arr[i] >> bit) & 1 == 0)
				push_operations(PUSH_B, &stack);
			
		}
		bit++;
	}

}
*/
int	max_bit_len(long num)
{
	int	bit_len;

	bit_len = 0;
	while (num != 0)
	{
		num = num >> 1;
		bit_len++;
	}
	return (bit_len);
}

