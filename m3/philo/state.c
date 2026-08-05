/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:57:04 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/05 20:26:25 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

bool	set_start(t_shared_data *data)
{
	if (pthread_mutex_lock(&data->start.mutex) != 0)
		return (false);
	data->start.is_start = true;
	if (pthread_mutex_unlock(&data->start.mutex) != 0)
		return (false);
	return (true);
}

bool	set_philos_end(t_shared_data *data)
{
	if (pthread_mutex_lock(&data->end.mutex) != 0)
		return (false);
	data->end.is_end = true;
	if (pthread_mutex_unlock(&data->end.mutex) != 0)
		return (false);
	return (true);
}

bool	check_philos_end(t_shared_data *data, bool *is_end)
{
	if (pthread_mutex_lock(&data->end.mutex) != 0)
		return (false);
	*is_end = data->end.is_end;
	if (pthread_mutex_unlock(&data->end.mutex) != 0)
		return (false);
	return (true);
}

bool	update_meal_time(t_meal *meal, long long start_time)
{
	if (pthread_mutex_lock(&meal->mutex) != 0)
		return (false);
	meal->last_time = start_time;
	if (pthread_mutex_unlock(&meal->mutex) != 0)
		return (false);
	return (true);
}

bool	update_meal_cnt(t_meal *meal)
{
	if (pthread_mutex_lock(&meal->mutex) != 0)
		return (false);
	meal->eat_cnt++;
	if (pthread_mutex_unlock(&meal->mutex) != 0)
		return (false);
	return (true);
}
