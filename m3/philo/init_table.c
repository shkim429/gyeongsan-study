/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 22:02:52 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 04:52:01 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "philo.h"

static bool	init_shared_data(int argc, char **argv, t_shared_data *data);
static bool	init_forks(t_table *table);

bool	init_table(int argc, char **argv, t_table *table)
{
	if (!init_shared_data(argc, argv, &table->data))
		return (false);
	if (!init_forks(table))
	{
		destroy_shared_data_mutex(&table->data);
		free(table->forks);
		return (false);
	}
	if (!init_philos(table))
	{
		destroy_fork_mutex(table->forks, table->data.philo_num);
		destroy_shared_data_mutex(&table->data);
		free(table->philos);
		free(table->forks);
		return (false);
	}
	return (true);
}

static bool	init_shared_data(int argc, char **argv, t_shared_data *data)
{
	if (!parse_args(argc, argv, data))
	{
		write(STDERR_FILENO, "Error: Invalid arguments\n", 25);
		return (false);
	}
	data->time_to_start = 0;
	data->end.is_end = false;
	data->start.is_start = false;
	if (pthread_mutex_init(&data->end.mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->end.mutex);
		return (false);
	}
	if (pthread_mutex_init(&data->start.mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&data->end.mutex);
		pthread_mutex_destroy(&data->print_mutex);
		return (false);
	}
	return (true);
}

static bool	init_forks(t_table *table)
{
	int	i;

	table->forks = malloc(table->data.philo_num * sizeof(*table->forks));
	if (table->forks == NULL)
		return (false);
	i = 0;
	while (i < table->data.philo_num)
	{
		table->forks[i].is_taken = false;
		if (pthread_mutex_init(&table->forks[i].mutex, NULL) != 0)
		{
			destroy_fork_mutex(table->forks, i);
			return (false);
		}
		i++;
	}
	return (true);
}
