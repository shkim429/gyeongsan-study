/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/06 22:11:29 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(const char *nptr);

int	main(int argc, char **argv)
{
	// int	*num_arr;
	int	num_arr[5];

	int	i;
	int	j;

	if (argc > 1)
	{
		// *num_arr = malloc((argc - 1) * sizeof(int));
		i = 1;
		j = 0;
		while (argv[i])
		{
			num_arr[j] = ft_atoi(argv[i]);
			printf("%d", num_arr[j]);
			i++;
			j++;
		}
	}
}

int	ft_sign(const char *nptr)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (nptr[i] == '+')
		sign = 1;
	else if (nptr[i] == '-')
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	num = 0;
	while (nptr[i])
	{
		while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
			i++;
		if (nptr[i] == '+' || nptr[i] == '-')
		{
			sign = ft_sign(&nptr[i]);
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
		{
			num = num * 10 + (nptr[i] - '0');
			i++;
		}
		return (num * sign);
	}
	return (0);
}

void	init(t_stack *s)
{
	s->head = NULL;
	s->size = 0;
}

void push(t_stack *s)
{
	
}


