/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 02:43:12 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/05 22:00:01 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "philo.h"

static bool	create_philo_threads(t_table *table);
static bool	join_all_threads(t_table *table);
static bool	join_philos_thread(t_philo *philos, int thread_cnt);
static bool	stop_and_join_threads(t_table *table, bool join_all);

bool	start_philos(t_table *table)
{
	bool	join_all;

	join_all = true;
	if (!create_philo_threads(table))
		return (false);
	if (pthread_create(&table->monitor_thread, NULL, run_monitor_task, \
table) != 0)
	{
		join_all = false;
		stop_and_join_threads(table, join_all);
		return (false);
	}
	if (!get_time_ms(&table->data.time_to_start))
	{
		stop_and_join_threads(table, join_all);
		return (false);
	}
	set_last_meal_times(table->philos, table->data.time_to_start);
	if (!set_start(&table->data))
	{
		stop_and_join_threads(table, join_all);
		return (false);
	}
	return (join_all_threads(table));
}

static bool	create_philo_threads(t_table *table)
{
	void	*(*routine)(void *);
	int		i;

	routine = run_philo_task;
	if (table->data.philo_num == 1)
		routine = run_single_philo_task;
	i = 0;
	while (i < table->data.philo_num)
	{
		if (pthread_create(&table->philos[i].thread, NULL, routine, \
&table->philos[i]) != 0)
		{
			set_philos_end(&table->data);
			join_philos_thread(table->philos, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	join_all_threads(t_table *table)
{
	bool	status;

	status = true;
	if (!join_philos_thread(table->philos, table->data.philo_num))
		status = false;
	if (pthread_join(table->monitor_thread, NULL) != 0)
		status = false;
	else if (table->monitor_status == THREAD_FAILURE)
		status = false;
	return (status);
}

static bool	join_philos_thread(t_philo *philos, int thread_cnt)
{
	bool	status;
	int		i;

	status = true;
	i = 0;
	while (i < thread_cnt)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			status = false;
		else if (philos[i].thread_status == THREAD_FAILURE)
			status = false;
		i++;
	}
	return (status);
}

static bool	stop_and_join_threads(t_table *table, bool join_all)
{
	bool	status;

	status = true;
	if (!set_philos_end(&table->data))
		status = false;
	if (!set_start(&table->data))
		status = false;
	if (join_all)
	{
		if (!join_all_threads(table))
			status = false;
	}
	else if (!join_philos_thread(table->philos, table->data.philo_num))
		status = false;
	return (status);
}
