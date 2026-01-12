/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:48 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/12 18:48:41 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>


void	swap_ops(t_stack_op_cmd cmd, t_stack *stacks)
{
	if (cmd == SWAP_A)
	{
		swap_stack(&(stacks->a));
		write(1, "sa\n", 3);
	}
	else if (cmd == SWAP_B)
	{
		swap_stack(&(stacks->b));
		write(1, "sb\n", 3);
	}
	else if (cmd == SWAP_AB)
	{
		swap_stack(&(stacks->a));
		swap_stack(&(stacks->b));
		write(1, "ss\n", 1);
	}
}

void	push_ops(t_stack_op_cmd cmd, t_stack *stacks)
{
	if (cmd == PUSH_A)
	{
		push_node(&(stacks->b), &(stacks->a));
		write(1, "pa\n", 3);
	}
	else if (cmd == PUSH_B)
	{
		push_node(&(stacks->a), &(stacks->b));
		write(1, "pb\n", 3);
	}
}

void	rotate_ops(t_stack_op_cmd cmd, t_stack *stacks)
{
	if (cmd == ROTATE_A)
	{
		rotate_node(&(stacks->a));
		write(1, "ra\n", 3);
	}
	else if (cmd == ROTATE_A)
	{
		rotate_node(&(stacks->b));
		write(1, "rb\n", 3);
	}
	else if (cmd == ROTATE_AB)
	{
		rotate_node(&(stacks->a));
		rotate_node(&(stacks->b));
		write(1, "rr\n", 3);
	}
}

void	rrotate_ops(t_stack_op_cmd cmd, t_stack *stacks)
{
	if (cmd == REVERSE_ROTATE_A)
	{
		rrotate_node(&(stacks->a));
		write(1, "rra\n", 4);
	}
	else if (cmd == REVERSE_ROTATE_B)
	{
		rrotate_node(&(stacks->b));
		write(1, "rrb\n", 3);
	}
	else if (cmd == REVERSE_ROTATE_AB)
	{
		rrotate_node(&(stacks->a));
		rrotate_node(&(stacks->b));
		write(1, "rrr\n", 3);
	}
}

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