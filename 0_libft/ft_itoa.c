/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:21:20 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/04 22:40:37 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n > 9)
	{
		len += intlen(n / 10);
	}
	len++;
	return (len);
}
char	*ft_itoa(int n)
{
	char	*str;
	int	size;
	int	i;
	
	if (n < 0)
		size = intlen(n) + 1;
	else
		size = intlen(n) + 1;	
	str = (char *)malloc(size);
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
	}
	i = intlen(n) - 1;
	if (n > 9)
	{
		while (i--)
		{
			str[i] = (n%10 + '0');
			n/=10;
		}
	}
	return (str);
}
int main()
{
	printf("%d\n", intlen(12));
	printf("%s", ft_itoa(12));
}