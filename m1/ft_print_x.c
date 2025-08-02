/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:22:50 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/02 15:10:41 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int x_num, int uppercase)
{
	char	*str;
	int		len;

	str = ft_utoa_base(x_num, 16, uppercase);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}

// #include <stdio.h>
// int main()
// {
// 	int len = ft_print_x(1024);
// 	printf("\n%d", len);
// }