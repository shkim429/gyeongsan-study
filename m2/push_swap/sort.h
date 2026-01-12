/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:57:50 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:24:45 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "push_swap.h"

int	find_max_value(t_list_node *stack);
int	find_min_value(t_list_node *stack);
int	is_sorted_des(t_node *start_node);
int	is_sorted_asc(t_node *start_node);
int	rank_stack_data(t_mem_res *var);
int	find_stack_data_rank(t_node *cur_node, t_mem_res *var);
int	is_visited(t_mem_res *var);
int	max_bit_len(long num);

#endif