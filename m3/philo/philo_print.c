/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:18:09 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 04:09:16 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

static void	print_message(t_philo *philo, char *message);

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
		print_message(philo, message);
	if (pthread_mutex_unlock(&philo->data->print_mutex) != 0)
		return (false);
	return (true);
}

bool	print_philo_taken_forks(t_philo *philo)
{
	long long	timestamp;
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
		timestamp = get_time_ms() - philo->data->time_to_start;
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
	print_message(philo, "died");
	if (pthread_mutex_unlock(&philo->data->print_mutex) != 0)
		return (false);
	return (true);
}

static void	print_message(t_philo *philo, char *message)
{
	long long	timestamp;

	timestamp = get_time_ms() - philo->data->time_to_start;
	printf("%lld %d %s\n", timestamp, philo->id, message);
}
