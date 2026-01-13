/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:57:26 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 17:15:49 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#include "push_swap.h"
#include "sort.h"
#include <stdlib.h>

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

int	is_sorted_des(t_node *start_node)
{
	t_node	*cur_node;

	cur_node = start_node;
	while (cur_node->next != NULL)
	{
		if (cur_node->data < cur_node->next->data)
			return (0);
		cur_node = cur_node->next;
	}
	return (1);
}

int	is_sorted_asc(t_node *start_node)
{
	t_node	*cur_node;

	cur_node = start_node;
	while (cur_node->next != NULL)
	{
		if (cur_node->data > cur_node->next->data)
		{
			return (0);
		}
		cur_node = cur_node->next;
	}
	return (1);
}
