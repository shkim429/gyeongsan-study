/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:03:26 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/05 19:17:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

bool	wait_for_start(t_shared_data *data)
{
	bool	is_start;

	while (true)
	{
		if (pthread_mutex_lock(&data->start.mutex) != 0)
			return (false);
		is_start = data->start.is_start;
		if (pthread_mutex_unlock(&data->start.mutex) != 0)
			return (false);
		if (is_start)
			return (true);
		usleep (100);
	}
}

bool	delay_even_philo(t_philo *philo)
{
	long long	start_time;
	long long	now;
	long long	delay;
	bool		is_end;

	if (philo->id % 2 != 0)
		return (true);
	if (!get_time_ms(&start_time))
		return (false);
	delay = ((long long)philo->data->time_to_eat / 2);
	while (true)
	{
		if (!get_time_ms(&now))
			return (false);
		if (!check_philos_end(philo->data, &is_end))
			return (false);
		if (is_end)
			return (true);
		if (now - start_time >= delay)
			return (true);
		usleep (100);
	}
}
