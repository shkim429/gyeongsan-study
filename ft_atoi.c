/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:21:03 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/21 19:28:28 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
