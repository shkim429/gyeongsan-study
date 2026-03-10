/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 03:08:34 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/10 16:52:49 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_INPUT_H
# define VALID_INPUT_H
# define NEGATIVE_NUM -1
# define NOT_NUM -1

# include "philo.h"
# include <stdbool.h>

/* valid_input_utils.c */

bool	is_sign(char c);
bool	is_num(char c);
bool	is_zero(char c);

/* valid_input.c */

long	*handle_input_data(int argc, char **argv, t_philo *philo_arg);
bool	check_invalid_int_len(char **argv);
bool	check_invalid_int_boundary(long num);
long	ft_atol(char *argv);

#endif