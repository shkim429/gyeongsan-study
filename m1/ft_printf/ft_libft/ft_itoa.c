/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:20 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/06 20:00:45 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		signed_nlen(long n);
int		sign_idx(int n);

char	*ft_itoa(int n)
{
	char	*str;
	long	long_n;
	int		i;
	int		min_idx;

	long_n = n;
	i = signed_nlen(long_n);
	min_idx = sign_idx(long_n);
	str = calloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (long_n < 0)
	{
		str[0] = '-';
		long_n = -long_n;
	}
	while (i >= min_idx)
	{
		str[i--] = (long_n % 10 + '0');
		long_n /= 10;
	}
	return (str);
}

int	signed_nlen(long long_n)
{
	int		len;

	len = 0;
	if (long_n < 0)
	{
		long_n = -long_n;
		len++;
	}
	if (long_n > 9)
		len += signed_nlen(long_n / 10);
	len++;
	return (len);
}

int	sign_idx(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}
