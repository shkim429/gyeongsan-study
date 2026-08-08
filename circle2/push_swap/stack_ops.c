/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:48 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 03:57:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_ops.h"
#include <stdlib.h>
#include <unistd.h>

void	swap_ops(t_stack_op_cmd cmd, t_stack *stack)
{
	if (cmd == SWAP_A)
	{
		swap_node(&(stack->a));
		write(1, "sa\n", 3);
	}
	else if (cmd == SWAP_B)
	{
		swap_node(&(stack->b));
		write(1, "sb\n", 3);
	}
	else if (cmd == SWAP_AB)
	{
		swap_node(&(stack->a));
		swap_node(&(stack->b));
		write(1, "ss\n", 1);
	}
}

void	push_ops(t_stack_op_cmd cmd, t_stack *stack)
{
	if (cmd == PUSH_A)
	{
		push_node(&(stack->b), &(stack->a));
		write(1, "pa\n", 3);
	}
	else if (cmd == PUSH_B)
	{
		push_node(&(stack->a), &(stack->b));
		write(1, "pb\n", 3);
	}
}

void	rotate_ops(t_stack_op_cmd cmd, t_stack *stack)
{
	if (cmd == ROTATE_A)
	{
		rotate_node(&(stack->a));
		write(1, "ra\n", 3);
	}
	else if (cmd == ROTATE_A)
	{
		rotate_node(&(stack->b));
		write(1, "rb\n", 3);
	}
	else if (cmd == ROTATE_AB)
	{
		rotate_node(&(stack->a));
		rotate_node(&(stack->b));
		write(1, "rr\n", 3);
	}
}

void	rrotate_ops(t_stack_op_cmd cmd, t_stack *stack)
{
	if (cmd == REVERSE_ROTATE_A)
	{
		rrotate_node(&(stack->a));
		write(1, "rra\n", 4);
	}
	else if (cmd == REVERSE_ROTATE_B)
	{
		rrotate_node(&(stack->b));
		write(1, "rrb\n", 3);
	}
	else if (cmd == REVERSE_ROTATE_AB)
	{
		rrotate_node(&(stack->a));
		rrotate_node(&(stack->b));
		write(1, "rrr\n", 3);
	}
}
