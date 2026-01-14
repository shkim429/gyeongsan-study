/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 11:46:34 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/14 14:53:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_hex_nlen(uintptr_t n, uintptr_t base);

char	*ft_utoa_base(uintptr_t n, uintptr_t base, int uppercase)
{
	char	*str;
	char	*hex_mapping_arr;
	int		hex_num;
	int		i;

	i = unsigned_hex_nlen(n, base);
	str = (char *)malloc(i + 1);
	if (uppercase)
		hex_mapping_arr = "0123456789ABCDEF";
	else
		hex_mapping_arr = "0123456789abcdef";
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n >= base)
	{
		hex_num = n % base;
		n /= base;
		str[i--] = hex_mapping_arr[hex_num];
	}
	str[i--] = hex_mapping_arr[n];
	return (str);
}

int	unsigned_hex_nlen(uintptr_t n, uintptr_t base)
{
	unsigned int	len;

	len = 0;
	if (n >= base)
		len += unsigned_hex_nlen(n / base, base);
	len++;
	return (len);
}
