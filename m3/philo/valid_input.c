/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:57:04 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/10 16:56:07 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_input.h"
#include "general_func_utils.h"
#include <stdint.h>

/* 인자 유효성 검사 (코드 가독성 다시 생각해 볼 것)*/
long	*handle_input_data(int argc, char **argv, t_philo *philo_arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	philo_arg->input_arr = ft_calloc(argc - 1, sizeof(long));
	if (philo_arg->input_arr == NULL)
		return (NULL);
	if (check_invalid_int_len(argv) == false)
		return (NULL);
	while (argv[++i])
	{
		/* 에러 변수 다시 생각해 볼 것 */
		if (ft_atol(argv[i]) == NEGATIVE_NUM || ft_atol(argv[i]) == NOT_NUM)
			return (NULL);
		else
		{
			philo_arg->input_arr[j] = ft_atol(argv[i]);
			if (check_invalid_int_boundary(philo_arg->input_arr[j++]) == false)
				return (NULL);
		}
	}
	return (philo_arg->input_arr);
}

bool	check_invalid_int_len(char **argv)
{
	int	i;
	int	j;
	int	num_len;

	i = 1;
	num_len = 0;
	while (argv[i])
	{
		num_len = 0;
		j = 0;
		if (is_sign(argv[i][j]) == true)
			j++;
		while (is_zero(argv[i][j]) == true)
			j++;
		while (is_num(argv[i][j]) == true)
		{
			num_len++;
			if (num_len > 10)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

long	ft_atol(char *argv)
{
	int64_t	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (argv[i] == '-')
		return (NEGATIVE_NUM);
	if (argv[i] == '+')
		i++;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			return (NOT_NUM);
		num = num * 10 + (argv[i] - '0');
		i++;
	}
	return (num * sign);
}

bool	check_invalid_int_boundary(long num)
{
	if (num < 0)
	{
		if (num < -2147483648)
			return (false);
	}
	else
	{
		if (num > 2147483647)
			return (false);
	}
	return (true);
}
