/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 01:57:04 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 19:45:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

bool	update_meal_state(t_meal *meal, long long start_time)
{
	if (pthread_mutex_lock(&meal->mutex) != 0)
		return (false);
	meal->last_time = start_time;
	meal->eat_cnt++;
	if (pthread_mutex_unlock(&meal->mutex) != 0)
		return (false);
	return (true);
}
