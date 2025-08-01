/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:26:28 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/01 17:42:56 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n > 9)
		len += nlen(n / 10);
	len++;
	return (len);
}

unsigned char	*ft_utoa(unsigned int n)
{
	unsigned char	*str;
	int				i;

	i = nlen(n);
	str = (unsigned char *)malloc(nlen(n) + i);
	if (str == NULL)
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = (n % 10 + '0');
		n /= 10;
	}
	return (str);
}

// #include <stdio.h>

// int main()
// {
// 	unsigned int num1 = 4294967295;
// 	printf("%s\n", ft_utoa(4294967295));
// 	printf("%d\n", -1);
// 	printf("%u", num1);
	
// }
