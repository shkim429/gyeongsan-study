/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:09:26 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 03:57:59 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H
# include "push_swap.h"

typedef enum s_stack_op_cmd
{
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_AB,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_AB
}	t_stack_op_cmd;

void	swap_node(t_list_node *stack);
void	push_node(t_list_node *stack1, t_list_node *stack2);
void	rotate_node(t_list_node *stack);
void	rrotate_node(t_list_node *stack);
void	swap_ops(t_stack_op_cmd cmd, t_stack *stack);
void	push_ops(t_stack_op_cmd cmd, t_stack *stack);
void	rotate_ops(t_stack_op_cmd cmd, t_stack *stack);
void	rrotate_ops(t_stack_op_cmd cmd, t_stack *stack);

#endif
