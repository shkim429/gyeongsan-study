/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:26:28 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/02 02:50:02 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_nlen(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n > 9)
		len += unsigned_nlen(n / 10);
	len++;
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	int		i;

	i = unsigned_nlen(n);
	str = (char *)malloc(unsigned_nlen(n) + i);
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
// 	unsigned long num1 = 4294967295;
// 	printf("%s\n", ft_utoa(num1));
// 	printf("%lu\n\n", num1);
// 	printf("%s\n", ft_utoa(-20));
// 	printf("%u\n", -20);
// }
