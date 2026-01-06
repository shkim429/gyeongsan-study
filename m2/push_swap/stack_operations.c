/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:48 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/06 04:52:09 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

/*
void	stack_operations(t_list_node *stack)
{
	if ()
	{
		swap_node12(&stack);
		write(1, "pa\n", 1);
	}

}
*/

void	swap_stack(t_list_node *stack)
{
	t_node	*tmp;

	tmp = stack->head->next;
	stack->head->next = stack->head->next->next;
	tmp->next = stack->head;
	stack->head = tmp;
}

void	push_node(t_list_node *stack1, t_list_node *stack2)
{
	t_node	*tmp;

	tmp = stack2->head->next;
	stack2->head->next = stack1->head;
	stack2->head = tmp;
}

void	rotate_node(t_list_node *stack)
{
	t_node	*tmp;

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