/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:20 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/19 15:50:31 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		signed_nlen(int n);
int		sign_idx(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		min_idx;

	i = signed_nlen(n);
	min_idx = sign_idx(n);
	str = (char *)malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (i >= min_idx)
	{
		str[i--] = (n % 10 + '0');
		n /= 10;
	}
	return (str);
}

int	signed_nlen(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n > 9)
		len += signed_nlen(n / 10);
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
