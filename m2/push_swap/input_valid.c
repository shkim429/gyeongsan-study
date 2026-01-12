/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:27:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:27:52 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_valid.h"
#include "error.h"
#include <stdint.h>

/* 입력값 = 숫자 확인 */
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

/* int 범위 오버/언더 여부 확인(10) */
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

/* 입력 문자열 -> 숫자 변환 */
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

/* int 범위 경계값(길이: 10) 오버/언더 확인 */
void	check_invalid_int_boundary(t_mem_res *var)
{
	int	i;

	i = 0;
	if (var->num_arr[i] < 0)
	{
		if (var->num_arr[i] < -2147483648)
			return (handle_error_case(ERROR_INT_BOUNDARY, var));
	}
	else
	{
		if (var->num_arr[i] > 2147483647)
			return (handle_error_case(ERROR_INT_BOUNDARY, var));
	}
}

/* 입력 숫자 중복 확인 */
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

