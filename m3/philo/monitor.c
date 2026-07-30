/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:04:07 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/30 19:41:58 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

static bool	check_philo_state(t_philo *philo, t_philo_state *state);
static bool	monitor_philos(t_table *table, bool *need_stop);

/* 수정 필요 */
void	*run_monitor_task(void *arg)
{
	t_table	*table;
	bool	need_stop;
	
	table = (t_table *)arg;
	table->monitor_status = TRHEAD_FAILURE;
	while (true)
	{
		need_stop = false;
		if (!monitor_philos(table, &need_stop))
			return (NULL);
		if (need_stop)
		{
			table->monitor_status = TRHEAD_SUCCESS;
			return (NULL);
		}
		// usleep(100);
	}
}

/* 수정 필요 */
static bool	monitor_philos(t_table *table, bool *need_stop)
{
	t_philo_state	state;
	bool			all_full;
	int			i;

	all_full = true;
	i = 0;
	while (i < table->data.philo_num)
	{
		if (!check_philo_state(&table->philos[i], &state))
			return (false);
		else if (state == PHILO_DEAD)
		{
			if (!set_philos_end(&table->data))
				return (false);
			*need_stop = true;
			return (print_philo_death(&table->philos[i]));
		}
		if (state != PHILO_FULL)
			all_full = false;
		i++;
	}
	if (all_full)
	{
		if (!set_philos_end(&table->data))
			return (false);
		*need_stop = true;
	}
	return (true);
}


static bool	check_philo_state(t_philo *philo, t_philo_state *state)
{
	*state = PHILO_ALIVE;
	if (pthread_mutex_lock(&philo->meal.mutex) != 0)
		return (false);
	if (philo->data->must_eat_cnt != NO_EAT_LIMIT &&
		philo->meal.eat_cnt >= philo->data->must_eat_cnt)
		*state = PHILO_FULL;
	if (get_time_ms() - philo->meal.last_time >= philo->data->time_to_die)
		*state = PHILO_DEAD;
	if (pthread_mutex_unlock(&philo->meal.mutex) != 0)
		return (false);
	return (true);
}
