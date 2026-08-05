/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:03:26 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/06 02:35:09 by sohuikim         ###   ########.fr       */
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

t_exec_state	delay_even_philo(t_philo *philo)
{
	long long		start_time;
	long long		now;
	long long		delay;
	t_exec_state	state;

	if (philo->id % 2 != 0)
		return (EXEC_RUNNING);
	if (!get_time_ms(&start_time))
		return (EXEC_ERROR);
	delay = ((long long)philo->data->time_to_eat / 2);
	while (true)
	{
		state = check_philos_end(philo->data);
		if (state != EXEC_RUNNING)
			return (state);
		if (!get_time_ms(&now))
			return (EXEC_ERROR);
		if (now - start_time >= delay)
			return (EXEC_RUNNING);
		usleep (100);
	}
}
