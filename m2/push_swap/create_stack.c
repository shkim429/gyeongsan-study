/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:36:21 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 01:39:01 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_stack.h"
#include <stdlib.h>

/* 스택 생성 */
int	create_stack_a(t_list_node *stack_a, t_mem_res *var)
{
	stack_a->head = create_new_node(var->num_arr[stack_a->size]);
	if (stack_a->head == NULL)
		return (FAILURE);
	stack_a->tail = stack_a->head;
	while (++(stack_a->size) < var->cnt_input)
	{
		stack_a->tail->next = create_new_node(var->num_arr[stack_a->size]);
		if (stack_a->tail->next == NULL)
			return (FAILURE);
		stack_a->tail = stack_a->tail->next;
	}
	return (1);
}

/* 노드 생성 */
t_node	*create_new_node(long num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = num;
	new_node->next = NULL;
	return (new_node);
}

/* 노드 연결 */
t_node	*addnode_back(t_node **cur_lst, t_node *new_node)
{
	if (*cur_lst == NULL)
		*cur_lst = new_node;
	else
		(*cur_lst)->next = new_node;
}
