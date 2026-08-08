/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:16:05 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 05:56:10 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	cleanup_table(t_table *table)
{
	destroy_meal_mutex(table->philos, table->data.philo_num);
	destroy_shared_data_mutex(&table->data);
	destroy_fork_mutex(table->forks, table->data.philo_num);
	free(table->philos);
	free(table->forks);
}

void	destroy_meal_mutex(t_philo *philos, int init_cnt)
{
	int	i;

	i = 0;
	while (i < init_cnt)
	{
		pthread_mutex_destroy(&philos[i].meal.mutex);
		i++;
	}
}

void	destroy_shared_data_mutex(t_shared_data *data)
{
	pthread_mutex_destroy(&data->end.mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->start.mutex);
}

void	destroy_fork_mutex(t_fork *forks, int init_cnt)
{
	int	i;

	i = 0;
	while (i < init_cnt)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
}
