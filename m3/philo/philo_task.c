/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:12:20 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/05 19:27:12 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static t_task_state	task_cycle(t_philo *philo);
static t_task_state	eating(t_philo *philo);
static t_task_state	sleeping(t_philo *philo);
static t_task_state	thinking(t_philo *philo);

void	*run_philo_task(void *arg)
{
	t_philo			*philo;
	t_task_state	state;
	bool			is_end;

	philo = (t_philo *)arg;
	philo->thread_status = THREAD_FAILURE;
	if (!wait_for_start(philo->data))
		return (NULL);
	if (!delay_even_philo(philo))
		return (NULL);
	while (true)
	{
		if (!check_philos_end(philo->data, &is_end))
			return (NULL);
		if (is_end)
			break ;
		state = task_cycle(philo);
		if (state == TASK_END)
			break ;
		if (state == TASK_ERROR)
			return (NULL);
	}
	philo->thread_status = THREAD_SUCCESS;
	return (NULL);
}

static t_task_state	task_cycle(t_philo *philo)
{
	t_task_state	state;
	
	state = pickup_forks(philo);
	if (state != TASK_RUNNING)
		return (state);
	state = eating(philo);
	if (!put_down_forks(philo))
		return (TASK_ERROR);
	if (state != TASK_RUNNING)
		return (state);
	state = sleeping(philo);
	if (state != TASK_RUNNING)
		return (state);
	state = thinking(philo);
	if (state != TASK_RUNNING)
		return (state);
	return (TASK_RUNNING);
}

static t_task_state	eating(t_philo *philo)
{
	long long	start_time;
	long long	now;
	bool		is_end;

	if (!get_time_ms(&start_time))
		return (TASK_ERROR);
	if (!update_meal_time(&philo->meal, start_time))
		return (TASK_ERROR);
	if (!print_philo_action(philo, "is eating"))
		return (TASK_ERROR);
	while (true)
	{
		if (!check_philos_end(philo->data, &is_end))
			return (TASK_ERROR);
		if (is_end)
			return (TASK_END);
		if (!get_time_ms(&now))
			return (TASK_ERROR);
		if (now - start_time >= philo->data->time_to_eat)
		{
			if (!update_meal_cnt(&philo->meal))
				return (TASK_ERROR);
			return (TASK_RUNNING);
		}
		usleep(100);
	}
}

static t_task_state	sleeping(t_philo *philo)
{
	long long	start_time;
	long long	now;
	bool		is_end;

	if (!get_time_ms(&start_time))
		return (TASK_ERROR);
	if (!print_philo_action(philo, "is sleeping"))
		return (TASK_ERROR);
	while (true)
	{
		if (!check_philos_end(philo->data, &is_end))
			return (TASK_ERROR);
		if (is_end)
			return (TASK_END);
		if (!get_time_ms(&now))
			return (TASK_ERROR);
		if (now - start_time >= philo->data->time_to_sleep)
			return (TASK_RUNNING);
		usleep(100);
	}
}

static t_task_state	thinking(t_philo *philo)
{
	if (!print_philo_action(philo, "is thinking"))
		return (TASK_ERROR);
	if (philo->data->philo_num % 2 == 0)
		return (TASK_RUNNING);
	usleep(250);
	return (TASK_RUNNING);
}
