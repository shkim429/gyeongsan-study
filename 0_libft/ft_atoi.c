/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:21:03 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/28 20:27:09 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(const char *nptr)
{
	int	sign;

	sign = 0;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	if (*nptr == '+')
	{
		sign = 1;
		nptr++;
	}
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;

	num = 0;
	sign = ft_sign(nptr);
	while (*nptr)
	{
		if (*nptr == '+' || *nptr == '-')
			nptr++;
		if (*nptr >= '0' && *nptr <= '9')
		{
			num = num * 10 + (*nptr - '0');
			nptr++;
		}
		else
			break ;
	}
	return (num * sign);
}
/*
int main(void)
{
	printf("atoi: %d\t", atoi("+23 er"));
	printf("ft_atoi: %d", ft_atoi("+23 er"));
}
*/
