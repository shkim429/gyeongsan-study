/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:49:29 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 01:55:09 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include "push_swap.h"

void	print_error(void);
void	free_num_arr(long *num_arr);
void	free_rank_arr(int *index_arr);
void	free_stack(t_list_node *stack);
void	free_split(char **splitstr_arr);
void	free_stack(t_list_node *stack);
void	free_res(t_error_case error, t_stack *stacks, t_mem_res *var);
void	handle_error_case(t_error_case error, t_mem_res *var);
#endif