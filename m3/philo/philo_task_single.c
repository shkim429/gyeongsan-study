/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 01:34:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 01:48:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static bool	pickup_single_fork(t_philo *philo);
static bool	put_down_single_fork(t_philo *philo);

void	*run_single_philo_task(void *arg)
{
	t_philo	*philo;
	bool	is_end;

	philo = (t_philo *)arg;
	philo->thread_status = TRHEAD_FAILURE;
	if (!wait_for_start(philo->data))
		return (NULL);
	if (!pickup_single_fork(philo))
		return (NULL);
	while (true)
	{
		if (!check_philos_end(philo->data, &is_end))
		{
			put_down_single_fork(philo);
			return (NULL);
		}
		if (is_end)
		{
			put_down_single_fork(philo);
			philo->thread_status = TRHEAD_SUCCESS;
			return (NULL);
		}
		usleep (300);
	}
}

static bool	pickup_single_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->first_fork->mutex) != 0)
		return (false);
	philo->first_fork->is_taken = true;
	if (pthread_mutex_unlock(&philo->first_fork->mutex) != 0)
		return (false);
	if (!print_philo_action(philo, "has taken a fork"))
	{
		put_down_single_fork(philo);
		return (false);
	}
	return (true);
}

static bool	put_down_single_fork(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->first_fork->mutex) != 0)
		return (false);
	philo->first_fork->is_taken = false;
	if (pthread_mutex_unlock(&philo->first_fork->mutex) != 0)
		return (false);
	return (true);
}
