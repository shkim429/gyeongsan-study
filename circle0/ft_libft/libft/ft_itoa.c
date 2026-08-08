/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:20 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/12 21:30:21 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nlen(int n);
int		sign_idx(int n);
char	*ft_strcpy(char *dest, const char *src);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		min_idx;

	i = nlen(n);
	min_idx = sign_idx(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = ft_calloc((i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
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

int	nlen(int n)
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
	{
		len += nlen(n / 10);
	}
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

char	*ft_strcpy(char *dest, const char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
