/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:16:05 by sohuikim          #+#    #+#             */
/*   Updated: 2026/07/28 15:32:37 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

/* 수정 필요 */
void	free_table(t_table *table)
{
	free(table->philos);
	free(table->forks);

}
