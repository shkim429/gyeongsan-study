/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_task_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 21:55:00 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/05 21:55:22 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_task_state	finish_eating(t_philo *philo)
{
	if (!update_meal_cnt(&philo->meal))
		return (TASK_ERROR);
	return (TASK_RUNNING);
}
