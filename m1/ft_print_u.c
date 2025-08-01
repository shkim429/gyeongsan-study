/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 07:16:31 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/02 02:47:07 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int u)
{
	char	*str;
	int		len;

	str = ft_utoa(u);
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