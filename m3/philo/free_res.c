/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_res.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:16:05 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/10 16:36:08 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "free.res.h"
#include <stdlib.h>

void	free_res(t_philo *philo_arg)
{
	if (philo_arg->input_arr != NULL)
		free_num_arr(philo_arg->input_arr);
}

void	free_num_arr(void *num_arr)
{
	free(num_arr);
	num_arr = NULL;
}
