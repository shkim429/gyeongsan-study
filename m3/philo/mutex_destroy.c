/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 17:03:26 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/27 16:22:51 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
