/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 07:16:31 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/12 01:25:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int u_num)
{
	char	*str;
	int		len;

	str = ft_utoa(u_num);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
// #include <stdio.h>
// int main()
// {
// 	int len = ft_print_u(429496729);
// 	printf("\n%d", len);
// }