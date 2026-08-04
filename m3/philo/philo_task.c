/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:12:20 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 22:11:09 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

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
	if (!wait_for_start(philo->data))
		return (NULL);
	if (!delay_even_philo(philo))
		return (NULL);
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
	if (!pickup_forks(philo))
		return (false);
	if (!eating(philo))
	{
		put_down_forks(philo);
		return (false);
	}
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
	long long	now;
	bool		is_end;

	if (!get_time_ms(&start_time))
		return (false);
	if (!update_meal_time(&philo->meal, start_time))
		return (false);
	if (!print_philo_action(philo, "is eating"))
		return (false);
	while (true)
	{
		if (!get_time_ms(&now))
			return (false);
		if (!check_philos_end(philo->data, &is_end))
			return (false);
		if (is_end)
			return (true);
		if (now - start_time >= philo->data->time_to_eat)
			return (update_meal_cnt(&philo->meal));
		usleep(100);
	}
}

static bool	sleeping(t_philo *philo)
{
	long long	start_time;
	long long	now;
	bool		is_end;

	if (!get_time_ms(&start_time))
		return (false);
	if (!print_philo_action(philo, "is sleeping"))
		return (false);
	if (!get_time_ms(&now))
		return (false);
	while (true)
	{
		if (!get_time_ms(&now))
			return (false);
		if (!check_philos_end(philo->data, &is_end))
			return (false);
		if (is_end)
			return (true);
		if (now - start_time >= philo->data->time_to_sleep)
			return (true);
		usleep(100);
	}
}

static bool	thinking(t_philo *philo)
{
	if (!print_philo_action(philo, "is thinking"))
		return (false);
	if (philo->data->philo_num % 2 == 0)
		return (true);
	usleep(250);
	return (true);
}
