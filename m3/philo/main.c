/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:18:18 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/05 20:50:38 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

#define NUM_TIMES 5

int	main(void)
{
	int				i;
	struct timeval	tv;

	for (i = 0; i < NUM_TIMES; i++)
	{
		gettimeofday(&tv, NULL);
		printf("%ld.%ld\n", (long)tv.tv_sec, (long)tv.tv_usec);
		sleep(1);
	}
	return (0);
}
