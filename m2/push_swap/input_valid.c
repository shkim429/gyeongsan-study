/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:27:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/14 02:25:51 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_valid.h"
#include "error.h"
#include <stdint.h>

void	check_invalid_num(t_mem_res *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->splitstr_arr[i])
	{
		j = 0;
		if (is_sign(var->splitstr_arr[i][j]))
			j++;
		while (is_num(var->splitstr_arr[i][j]))
		{
			if (var->splitstr_arr[i][j + 1] == '\0')
				break ;
			j++;
		}
		if ((is_sign(var->splitstr_arr[i][j])) || \
			(!(is_num(var->splitstr_arr[i][j]))))
			return (handle_error_case(ERROR_NUM, var));
		i++;
	}
	return ;
}

void	check_invalid_int_len(t_mem_res *var)
{
	int	i;
	int	j;
	int	num_len;

	i = 0;
	num_len = 0;
	while (var->splitstr_arr[i])
	{
		num_len = 0;
		j = 0;
		if (is_sign(var->splitstr_arr[i][j]))
			j++;
		while (is_zero(var->splitstr_arr[i][j]))
			j++;
		while (is_num(var->splitstr_arr[i][j]))
		{
			num_len++;
			if (num_len > 10)
				return (handle_error_case(ERROR_INT_LEN, var));
			j++;
		}
		i++;
	}
	return ;
}

long	ft_atol(char *splitstr)
{
	int64_t	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (splitstr[i] == '+')
		i++;
	else if (splitstr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (splitstr[i])
	{
		num = num * 10 + (splitstr[i] - '0');
		i++;
	}
	return (num * sign);
}

void	check_invalid_int_boundary(long num, t_mem_res *var)
{
	if (num < 0)
	{
		if (num < -2147483648)
			return (handle_error_case(ERROR_INT_BOUNDARY, var));
	}
	else
	{
		if (num > 2147483647)
			return (handle_error_case(ERROR_INT_BOUNDARY, var));
	}
}

void	check_duplicate_num(t_mem_res *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->cnt_input)
	{
		j = i + 1;
		while (j < var->cnt_input)
		{
			if (var->num_arr[i] == var->num_arr[j])
				return (handle_error_case(ERROR_DUPLICATE_NUM, var));
			j++;
		}
		i++;
	}
}
