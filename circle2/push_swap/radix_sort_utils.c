/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 02:02:08 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/15 14:09:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		min = is_ranked(var);
		if (min == var->cnt_input)
			return (SUCCESS);
		j = min + 1;
		while (j < var->cnt_input)
		{
			if (var->index_arr[j] == NOT_RANKED && \
				var->num_arr[min] > var->num_arr[j])
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

int	is_ranked(t_mem_res *var)
{
	int	k;

	k = 0;
	while (k < var->cnt_input)
	{
		if (var->index_arr[k] == NOT_RANKED)
			return (k);
		k++;
	}
	return (k);
}
