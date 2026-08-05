/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task_cycle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 01:33:04 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/06 03:51:01 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static t_exec_state	eating(t_philo *philo);
static t_exec_state	eating_with_forks(t_philo *philo);
static t_exec_state	sleeping(t_philo *philo);
static t_exec_state	thinking(t_philo *philo);

t_exec_state	task_cycle(t_philo *philo)
{
	t_exec_state	state;

	state = eating_with_forks(philo);
	if (state != EXEC_RUNNING)
		return (state);
	state = check_philos_end(philo->data);
	if (state != EXEC_RUNNING)
		return (state);
	state = sleeping(philo);
	if (state != EXEC_RUNNING)
		return (state);
	state = check_philos_end(philo->data);
	if (state != EXEC_RUNNING)
		return (state);
	return (thinking(philo));
}

t_exec_state	eating_with_forks(t_philo *philo)
{
	t_exec_state	state;

	state = pickup_forks(philo);
	if (state != EXEC_RUNNING)
		return (state);
	state = check_philos_end(philo->data);
	if (state != EXEC_RUNNING)
	{
		if (!put_down_forks(philo))
			return (EXEC_ERROR);
		return (state);
	}
	state = eating(philo);
	if (state == EXEC_RUNNING)
	{
		if (!update_meal_cnt(&philo->meal))
			state = EXEC_ERROR;
	}
	if (!put_down_forks(philo))
		return (EXEC_ERROR);
	return (state);
}

static t_exec_state	sleeping(t_philo *philo)
{
	long long		start_time;
	long long		now;
	t_exec_state	state;

	if (!get_time_ms(&start_time))
		return (EXEC_ERROR);
	state = print_philo_action(philo, "is sleeping");
	if (state != EXEC_RUNNING)
		return (state);
	while (true)
	{
		state = check_philos_end(philo->data);
		if (state != EXEC_RUNNING)
			return (state);
		if (!get_time_ms(&now))
			return (EXEC_ERROR);
		if (now - start_time >= philo->data->time_to_sleep)
			return (EXEC_RUNNING);
		usleep(100);
	}
}

static t_exec_state	thinking(t_philo *philo)
{
	t_exec_state	state;

	state = print_philo_action(philo, "is thinking");
	if (state != EXEC_RUNNING)
		return (state);
	if (philo->data->philo_num % 2 == 0)
		return (EXEC_RUNNING);
	usleep(250);
	return (EXEC_RUNNING);
}

static t_exec_state	eating(t_philo *philo)
{
	long long		start_time;
	long long		now;
	t_exec_state	state;

	if (!get_time_ms(&start_time))
		return (EXEC_ERROR);
	if (!update_meal_time(&philo->meal, start_time))
		return (EXEC_ERROR);
	state = print_philo_action(philo, "is eating");
	if (state != EXEC_RUNNING)
		return (state);
	while (true)
	{
		state = check_philos_end(philo->data);
		if (state != EXEC_RUNNING)
			return (state);
		if (!get_time_ms(&now))
			return (EXEC_ERROR);
		if (now - start_time >= philo->data->time_to_eat)
			return (EXEC_RUNNING);
		usleep(100);
	}
}
