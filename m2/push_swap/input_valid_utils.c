/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_valid_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 01:15:06 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 17:15:29 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 입력값 형태: 부호 확인 */
int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

/* 입력값 형태: 숫자 확인 */
int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/* 입력값 길이 검사: 0 건너뛰기*/
int	is_zero(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

/* 입력값 정렬 여부 검사 */
int	check_valid_sort_state(t_mem_res *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < (var->cnt_input) - 1)
	{
		if (var->num_arr[i] > var->num_arr[i + 1])
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}
