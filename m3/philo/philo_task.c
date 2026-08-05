/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 03:12:20 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/06 03:00:23 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "philo.h"

void	*run_philo_task(void *arg)
{
	t_philo			*philo;
	t_exec_state	state;

	philo = (t_philo *)arg;
	philo->thread_status = THREAD_FAILURE;
	if (!wait_for_start(philo->data))
		return (NULL);
	state = delay_even_philo(philo);
	while (state == EXEC_RUNNING)
	{
		state = check_philos_end(philo->data);
		if (state == EXEC_RUNNING)
			state = task_cycle(philo);
	}
	if (state == EXEC_END)
		philo->thread_status = THREAD_SUCCESS;
	return (NULL);
}
