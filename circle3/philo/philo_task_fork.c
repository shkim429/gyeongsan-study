/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:24:57 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/06 03:25:05 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static bool	try_pickup_forks(t_philo *philo, bool *picked_up);
static bool	lock_forks(t_fork *first, t_fork *second);
static bool	unlock_forks(t_fork *first, t_fork *second);

t_exec_state	pickup_forks(t_philo *philo)
{
	bool			picked_up;
	t_exec_state	state;

	while (true)
	{
		state = check_philos_end(philo->data);
		if (state != EXEC_RUNNING)
			return (state);
		if (!try_pickup_forks(philo, &picked_up))
			return (EXEC_ERROR);
		if (picked_up)
		{
			state = print_philo_taken_forks(philo);
			if (state != EXEC_RUNNING)
			{
				if (!put_down_forks(philo))
					return (EXEC_ERROR);
				return (state);
			}
			return (EXEC_RUNNING);
		}
		usleep (100);
	}
}

static bool	try_pickup_forks(t_philo *philo, bool *picked_up)
{
	*picked_up = false;
	if (!lock_forks(philo->first_fork, philo->second_fork))
		return (false);
	if (!philo->first_fork->is_taken && !philo->second_fork->is_taken)
	{
		philo->first_fork->is_taken = true;
		philo->second_fork->is_taken = true;
		*picked_up = true;
	}
	if (!unlock_forks(philo->first_fork, philo->second_fork))
		return (false);
	return (true);
}

bool	put_down_forks(t_philo *philo)
{
	if (!lock_forks(philo->first_fork, philo->second_fork))
		return (false);
	philo->first_fork->is_taken = false;
	philo->second_fork->is_taken = false;
	if (!unlock_forks(philo->first_fork, philo->second_fork))
		return (false);
	return (true);
}

static bool	lock_forks(t_fork *first, t_fork *second)
{
	if (pthread_mutex_lock(&first->mutex) != 0)
		return (false);
	if (pthread_mutex_lock(&second->mutex) != 0)
	{
		pthread_mutex_unlock(&first->mutex);
		return (false);
	}
	return (true);
}

static bool	unlock_forks(t_fork *first, t_fork *second)
{
	bool	status;

	status = true;
	if (pthread_mutex_unlock(&second->mutex) != 0)
		status = false;
	if (pthread_mutex_unlock(&first->mutex) != 0)
		status = false;
	return (status);
}
