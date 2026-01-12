/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:11:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/12 23:29:27 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_node	*find_midnode_pos(t_list_node *stack_a);
int		max_bit_len(long num);
int		is_sorted_asc(t_node *start_node);
int		is_sorted_des(t_node *start_node);

int	find_max_value(t_list_node *stack)
{
	t_node	*cur_node;
	int		max_value;
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

int	find_min_value(t_list_node *stack)
{
	t_node	*cur_node;
	int		min_value;
	int		i;

	cur_node = stack->head;
	min_value = cur_node->data;
	i = 0;
	while (++i < stack->size)
	{
		cur_node = cur_node->next;
		if (min_value > cur_node->data)
			min_value = cur_node->data;
	}
	return (min_value);
}

int	run_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils)
{
	if (var->cnt_input <= 5)
		insert_sort_controller(stacks, sort_utils);
	else
	{
		if (!indexing_stack_data(var))
			return (FAILURE);
		binary_radix_sort(stacks, var, sort_utils);
	}
	return (SUCCESS);
}

void	binary_radix_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils)
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

int	is_sorted_asc(t_node *start_node)
{
	t_node	*cur_node;

	cur_node = start_node;
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

int	is_sorted_des(t_node *start_node)
{
	t_node	*cur_node;

	cur_node = start_node;
	while (cur_node->next != NULL)
	{
		if (cur_node->data < cur_node->next->data)
			return (0); // not sorted
		cur_node = cur_node->next;
	}
	return (1);
}


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
int	is_visited(t_mem_res *var)
{
	int	k;

	k = 0;
	while (k < var->cnt_input)
	{
		if (var->index_arr[k] == -1)
			return (k);
		k++;
	}
	return (k);
}

int	indexing_stack_data(t_mem_res *var)
{
	int		i;
	int		j;
	int		min;

	var->index_arr = malloc((var->cnt_input) * sizeof(*var->index_arr));
	if (var->index_arr == NULL)
		return (FAILURE);
	ft_memset(var->index_arr, -1, (var->cnt_input * sizeof(*var->index_arr)));
	i = 0;
	while (i < var->cnt_input)
	{

		min = is_visited(var);
		if (min == var->cnt_input)
			return (SUCCESS);
		j = min + 1;
		while (j < var->cnt_input)
		{
			if (var->index_arr[j] == -1 && var->num_arr[min] > var->num_arr[j])
				min = j;
			j++;
		}
		var->index_arr[min] = i++;
	}
	return (SUCCESS);
}

int	find_stack_data_rank(t_node *cur_node, t_mem_res *var)
{
	int	i;
	int	rank;

	i = 0;
	rank = 0;
	while (i < var->cnt_input)
	{
		if (cur_node->data == var->num_arr[i])
			break ;
		i++;
	}
	rank = var->index_arr[i];
	return (rank);
}
