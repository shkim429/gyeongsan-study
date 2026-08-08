/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:18:18 by sohuikim          #+#    #+#             */
/*   Updated: 2026/08/04 12:53:43 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 5 || argc > 6)
	{
		write(STDERR_FILENO, "Error: Invalid number of arguments\n", 35);
		return (1);
	}
	if (!init_table(argc, argv, &table))
		return (1);
	if (!start_philos(&table))
		return (1);
	cleanup_table(&table);
	return (0);
}
