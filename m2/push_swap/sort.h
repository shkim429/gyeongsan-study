/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:57:50 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/15 05:14:51 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# define SORTED 1
# define NOT_SORTED 0

# include "push_swap.h"

int		find_max_value(t_list_node *stack);
int		find_min_value(t_list_node *stack);
int		is_sorted_des(t_node *start_node);
int		is_sorted_asc(t_node *start_node);
int		rank_stack_data(t_mem_res *var);
int		find_stack_data_rank(t_node *cur_node, t_mem_res *var);
int		is_ranked(t_mem_res *var);
int		run_sort(t_stack *stack, t_mem_res *var, t_sort_utils *sort_utils);
void	run_insert_sort(t_stack *stack, t_sort_utils *sort_utils, int a_size);
void	insert_sort(t_stack *stack, t_sort_utils *sort_utils);
void	binary_radix_sort(t_stack *stack, t_mem_res *var);

#endif