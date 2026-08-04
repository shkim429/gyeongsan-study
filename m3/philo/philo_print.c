/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:18:09 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 21:49:40 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static bool	print_message(t_philo *philo, char *message);

bool	print_philo_action(t_philo *philo, char *message)
{
	bool		is_end;

	if (pthread_mutex_lock(&philo->data->print_mutex) != 0)
		return (false);
	if (!check_philos_end(philo->data, &is_end))
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (false);
	}
	if (!is_end)
	{
		if (!print_message(philo, message))
			return (false);
	}
	if (pthread_mutex_unlock(&philo->data->print_mutex) != 0)
		return (false);
	return (true);
}

bool	print_philo_taken_forks(t_philo *philo)
{
	long long	timestamp;
	long long	now;
	bool		is_end;

	if (pthread_mutex_lock(&philo->data->print_mutex) != 0)
		return (false);
	if (!check_philos_end(philo->data, &is_end))
	{
		pthread_mutex_unlock(&philo->data->print_mutex);
		return (false);
	}
	if (!is_end)
	{
		if (!get_time_ms(&now))
			return (false);
		timestamp = now - philo->data->time_to_start;
		printf("%lld %d %s\n", timestamp, philo->id, "has taken a fork");
		printf("%lld %d %s\n", timestamp, philo->id, "has taken a fork");
	}
	if (pthread_mutex_unlock(&philo->data->print_mutex) != 0)
		return (false);
	return (true);
}

bool	print_philo_death(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->print_mutex) != 0)
		return (false);
	if (!print_message(philo, "died"))
		return (false);
	if (pthread_mutex_unlock(&philo->data->print_mutex) != 0)
		return (false);
	return (true);
}

static bool	print_message(t_philo *philo, char *message)
{
	long long	timestamp;
	long long	now;

	if (!get_time_ms(&now))
		return (false);
	timestamp = now - philo->data->time_to_start;
	printf("%lld %d %s\n", timestamp, philo->id, message);
	return (true);
}
