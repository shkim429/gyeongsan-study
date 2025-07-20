/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:21:03 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 21:01:29 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/09 15:08:39 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sign(const char *nptr)
{
<<<<<<< HEAD
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (nptr[i] == '+')
		sign = 1;
	else if (nptr[i] == '-')
		sign = -1;
=======
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
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
	return (sign);
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
<<<<<<< HEAD
	int	i;

	sign = 1;
	i = 0;
	num = 0;
	while (nptr[i] != '\0')
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
/*
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

int main(void)
{
	printf("atoi: %d\t", atoi("++0"));
	printf("ft_atoi: %d", ft_atoi("++0"));
}
*/
=======

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

// # include <unistd.h>
// # include <string.h>
// # include <stdlib.h>
// # include <stdio.h>

// int main(void)
// {
// 	printf("atoi: %d\t", atoi("2147483648"));
// 	printf("ft_atoi: %d", ft_atoi("2147483648"));
// }
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
