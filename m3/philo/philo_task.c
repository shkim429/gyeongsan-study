/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:12:20 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 20:29:33 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

/* 나중에 지우기 */
#include <stdio.h>

static bool	task_cycle(t_philo *philo);
static bool	eating(t_philo *philo);
static bool	sleeping(t_philo *philo);
static bool	thinking(t_philo *philo);

void	*run_philo_task(void *arg)
{
	t_philo	*philo;
	bool	is_end;

	philo = (t_philo *)arg;
	philo->thread_status = TRHEAD_FAILURE;
	while (true)
	{
		if (!check_philos_end(philo->data, &is_end))
			return (NULL);
		if (is_end)
		{
			philo->thread_status = TRHEAD_SUCCESS;
			return (NULL);
		}
		if (!task_cycle(philo))
			return (NULL);
	}
}

static bool	task_cycle(t_philo *philo)
{
	if (!pick_up_forks(philo))
		return (false);
	if (!eating(philo))
	{
		put_down_forks(philo);
		return (false);
	}
	printf("%d) 먹은 횟수: %d\n", philo->id, philo->meal.eat_cnt);  /* 나중에 지우기 */
	if (!put_down_forks(philo))
		return (false);
	if (!sleeping(philo))
		return (false);
	if (!thinking(philo))
		return (false);
	return (true);		
}

static bool	eating(t_philo *philo)
{
	long long	start_time;
	bool		is_end;
	
	start_time = get_time_ms();
	if (!print_philo_action(philo, "is eating"))
		return (false);
	if (!update_meal_state(&philo->meal, start_time))
		return (false);
	while (get_time_ms() - start_time < philo->data->time_to_eat)
	{
		if (!check_philos_end(philo->data, &is_end))
			return (false);
		if (is_end)
			return (true);
		usleep(100);
	}
	return (true);
}

static bool	sleeping(t_philo *philo)
{
	long long	start_time;
	bool		is_end;

	start_time = get_time_ms();
	if (!print_philo_action(philo, "is sleeping"))
		return (false);
	while (get_time_ms() - start_time < philo->data->time_to_sleep)
	{
		if (!check_philos_end(philo->data, &is_end))
			return (false);
		if (is_end)
			return (true);
		usleep(100);
	}
	return (true);
}

static bool	thinking(t_philo *philo)
{
	if (!print_philo_action(philo, "is thinking"))
		return (false);
	usleep(1000);
	return (true);
}
