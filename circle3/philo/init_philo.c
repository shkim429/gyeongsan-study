/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:07:12 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/03 23:07:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static bool	init_philo(t_philo *philo, t_fork *forks, t_shared_data *data, \
int i);
static void	assign_philo_forks(t_philo *philo, t_fork *forks, \
int i);

bool	init_philos(t_table *table)
{
	int	i;

	table->philos = malloc(table->data.philo_num * sizeof(*table->philos));
	if (table->philos == NULL)
		return (false);
	i = 0;
	while (i < table->data.philo_num)
	{
		if (!init_philo(&table->philos[i], table->forks, &table->data, i))
		{
			destroy_meal_mutex(table->philos, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_philo(t_philo *philo, t_fork *forks, t_shared_data *data, \
int i)
{
	philo->id = i + 1;
	philo->meal.last_time = 0;
	philo->meal.eat_cnt = 0;
	philo->data = data;
	assign_philo_forks(philo, forks, i);
	if (pthread_mutex_init(&philo->meal.mutex, NULL) != 0)
		return (false);
	return (true);
}

static void	assign_philo_forks(t_philo *philo, t_fork *forks, int i)
{
	if (i == philo->data->philo_num - 1)
	{
		philo->first_fork = &forks[0];
		philo->second_fork = &forks[i];
	}
	else
	{
		philo->first_fork = &forks[i];
		philo->second_fork = &forks[i + 1];
	}
}

void	set_last_meal_times(t_philo *philos, long long start_time)
{
	int	i;

	i = 0;
	while (i < philos->data->philo_num)
	{
		philos[i].meal.last_time = start_time;
		i++;
	}
}
