/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:42:01 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:25:25 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALID_H
# define INPUT_VALID_H
# include "push_swap.h"

int		is_sign(char c);
int		is_num(char c);
int		is_zero(char c);
long	ft_atol(char *splitstr);
int		check_vaild_sort_state(t_mem_res *var);
void	check_invalid_num(t_mem_res *var);
void	check_invalid_int_len(t_mem_res *var);
void	check_invalid_int_boundary(t_mem_res *var);
void	check_duplicate_num(t_mem_res *var);

#endif