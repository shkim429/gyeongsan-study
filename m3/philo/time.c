/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 22:47:58 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 21:45:37 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include "philo.h"

/* 현재 시간(ms) 계산*/ // 실패 처리 리팩토링 필요
bool	get_time_ms(long long *now)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		return (false);
	*now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (true);
}
