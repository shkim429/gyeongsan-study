/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task_single.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 01:34:27 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/06 03:50:15 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static t_exec_state	pickup_single_fork(t_philo *philo);
static bool			put_down_single_fork(t_philo *philo);

void	*run_single_philo_task(void *arg)
{
	t_philo			*philo;
	t_exec_state	state;

	philo = (t_philo *)arg;
	philo->thread_status = THREAD_FAILURE;
	if (!wait_for_start(philo->data))
		return (NULL);
	state = pickup_single_fork(philo);
	while (state == EXEC_RUNNING)
	{
		state = check_philos_end(philo->data);
		if (state == EXEC_RUNNING)
			usleep (300);
	}
	if (!put_down_single_fork(philo))
		return (NULL);
	if (state == EXEC_END)
		philo->thread_status = THREAD_SUCCESS;
	return (NULL);
}

static t_exec_state	pickup_single_fork(t_philo *philo)
{
	t_exec_state	state;

	if (pthread_mutex_lock(&philo->first_fork->mutex) != 0)
		return (false);
	philo->first_fork->is_taken = true;
	if (pthread_mutex_unlock(&philo->first_fork->mutex) != 0)
		return (false);
	state = print_philo_action(philo, "has taken a fork");
	if (!put_down_single_fork(philo))
		return (false);
	return (state);
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
