/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:18:18 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 17:24:59 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

static bool	start_philos(t_table *table);
static bool	create_philo_threads(t_table *table);
static bool	join_all_threads(t_table *table);
static bool	join_philos_thread(t_philo *philos, int thread_cnt);

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Error: Invalid number of arguments\n", 35);
		return (EXIT_FAILURE);
	}
	if (!init_table(argc, argv, &table))
		return (EXIT_FAILURE);
	if (!start_philos(&table))
	{
		free_table(&table);
		return (EXIT_FAILURE);
	}
	free_table(&table);
	return (0);
}

static bool	start_philos(t_table *table)
{
	table->data.time_to_start = get_time_ms();
	set_last_meal_times(table->philos, table->data.time_to_start);
	if (!create_philo_threads(table))
		return (false);
	if (pthread_create(&table->monitor_thread, NULL, run_monitor_task, table) != 0)
		return (false);
	if (!join_all_threads(table))
		return (false);
	return (true);
}

static bool	create_philo_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->data.philo_num)
	{
		if (pthread_create(&table->philos[i].thread, NULL, run_philo_task, &table->philos[i]) != 0)
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
	else if (table->monitor_status == TRHEAD_FAILURE)
		status = false;
	return (status);
}

static bool	join_philos_thread(t_philo *philos, int thread_cnt)
{
	bool	status;
	int	i;

	status = true;
	i = 0;
	while (i < thread_cnt)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
			status = false;
		else if (philos[i].thread_status == TRHEAD_FAILURE)
			status = false;
		i++;
	}
	return (status);
}

// 정리 필요
