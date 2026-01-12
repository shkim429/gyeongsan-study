/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res_uitls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:17:06 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 01:53:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_num_arr(long *num_arr)
{
	free(num_arr);
	num_arr = NULL;
}

void	free_rank_arr(int *index_arr)
{
	free(index_arr);
	index_arr = NULL;
}

void	free_split(char **splitstr_arr)
{
	int	i;

	i = 0;
	while (splitstr_arr[i])
	{
		free(splitstr_arr[i]);
		i++;
	}
	free(splitstr_arr);
	splitstr_arr = NULL;
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

