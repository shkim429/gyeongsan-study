/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 02:57:54 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 20:23:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "philo.h"

static int	str_to_positive_int(char *str);
static bool	is_valid_num_arg(char *str, int *i);

bool	parse_args(int argc, char **argv, t_shared_data *data)
{
	data->philo_num = str_to_positive_int(argv[1]);
	if (data->philo_num == INVALID_NUM)
		return (false);
	data->time_to_die = str_to_positive_int(argv[2]);
	if (data->time_to_die == INVALID_NUM)
		return (false);
	data->time_to_eat = str_to_positive_int(argv[3]);
	if (data->time_to_eat == INVALID_NUM)
		return (false);
	data->time_to_sleep = str_to_positive_int(argv[4]);
	if 	(data->time_to_sleep == INVALID_NUM)
		return (false);
	data->must_eat_cnt = NO_EAT_LIMIT;	
	if (argc == 6)
	{
		data->must_eat_cnt = str_to_positive_int(argv[5]);
		if (data->must_eat_cnt == INVALID_NUM)
			return (false);
	}
	return (true);
}

static int	str_to_positive_int(char *str)
{
	int		num;
	int		i;

	num = 0;
	i = 0;

	if (!is_valid_num_arg(str, &i))
		return (INVALID_NUM);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (INVALID_NUM);
		if (num > (INT_MAX - (str[i] - '0')) / 10)
			return (INVALID_NUM);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (num == 0)
		return (INVALID_NUM);
	return (num);
}

static bool	is_valid_num_arg(char *str, int *i)
{
	if (str[*i] == '-')
		return (false);
	if (str[*i] == '+')
	{
		(*i)++;
		if (str[*i] == '\0')
			return (false);
	}
	return (true);
}