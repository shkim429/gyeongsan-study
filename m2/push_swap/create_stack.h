/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:36:48 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 01:38:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CREATE_STACK_H
# define CREATE_STACK_H
# include "push_swap.h"

int		create_stack_a(t_list_node *stack_a, t_mem_res *var);
t_node	*create_new_node(long num);
t_node	*addnode_back(t_node **cur_lst, t_node *new_node);

#endif