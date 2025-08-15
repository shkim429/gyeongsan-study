/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 07:16:31 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/15 13:58:06 by sohuikim         ###   ########.fr       */
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
// 	unsigned int u_num = 4294967295;
// 	int len_ft_u = ft_print_u(u_num);
// 	printf("\t");
// 	int len_u = printf("%u", u_num);
// 	printf("\n%d %d", len_ft_u, len_u);
// }