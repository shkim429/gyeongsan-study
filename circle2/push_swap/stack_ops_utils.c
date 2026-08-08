/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:23:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:12:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"
#include <stdlib.h>

void	swap_node(t_list_node *stack)
{
	t_node	*tmp;

	tmp = stack->head->next;
	stack->head->next = stack->head->next->next;
	tmp->next = stack->head;
	stack->head = tmp;
}

void	push_node(t_list_node *stack1, t_list_node *stack2)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = stack1->head->next;
	tmp2 = stack2->head;
	stack2->head = stack1->head;
	stack2->head->next = tmp2;
	stack2->size++;
	if (stack2->size == 1)
		stack2->tail = stack2->head;
	stack1->head = tmp1;
	stack1->size--;
}

void	rotate_node(t_list_node *stack)
{
	t_node	*tmp;

	if (stack->size == 1)
		return ;
	tmp = stack->head->next;
	stack->tail->next = stack->head;
	stack->tail = stack->head;
	stack->head = tmp;
	stack->tail->next = NULL;
}

void	rrotate_node(t_list_node *stack)
{
	t_node	*tmp;
	int		i;

	if (stack->size == 1)
		return ;
	i = 1;
	tmp = stack->head;
	while (i < (stack->size) - 1)
	{
		tmp = tmp->next;
		i++;
	}
	stack->tail->next = stack->head;
	stack->head = stack->tail;
	stack->tail = tmp;
	stack->tail->next = NULL;
}
