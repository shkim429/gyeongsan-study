/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 21:24:57 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 20:26:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"
/* 나중에 아래 지우기 */
#include <stdio.h>

static bool	lock_forks(t_fork *first, t_fork *second);
static bool	unlock_forks(t_fork *first, t_fork *second);

bool	pick_up_forks(t_philo *philo)
{
	bool	picked_up;
	bool	is_end;

	while (true)
	{
		picked_up = false;
		if (!check_philos_end(philo->data, &is_end))
			return (false);
		if (is_end)
			return (true);
		if (!lock_forks(philo->first_fork, philo->second_fork))
			return (false);
		if (!philo->first_fork->is_taken && !philo->second_fork->is_taken)
		{
			philo->first_fork->is_taken = true;
			philo->second_fork->is_taken = true;
			picked_up = true;
		}
		if (!unlock_forks(philo->first_fork, philo->second_fork))
			return (false);
		if (picked_up)
		{
			if (!print_philo_taken_forks(philo))
			{
				put_down_forks(philo);
				return (false);
			}
			return (true);
		}
		usleep(100);
	}
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

