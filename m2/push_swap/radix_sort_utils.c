/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 02:02:08 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:26:44 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

#include "push_swap.h"
#include "libft.h"
#include "sort.h"
#include <stdlib.h>

int	rank_stack_data(t_mem_res *var)
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
