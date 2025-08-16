/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:15:22 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/15 13:23:47 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *ptr, int uppercase)
{
	char	*str;
	int		len;

	if (ptr == NULL)
		return (write(1, "(nil)", ft_strlen("(nil)")));
	str = ft_utoa_base((uintptr_t)ptr, 16, uppercase);
	len = ft_strlen(str);
	write(1, "0x", 2);
	write(1, str, len);
	return (2 + len);
}
// #include <stdio.h>
// int main()
// {
// 	char *str = "123";
// 	int len = ft_print_p(str, 0);
// 	printf("\n%d\n", len);
// 	printf("%p", str);
// 	printf("\n%s", str);
// }

// #include <stdio.h>
// int main()
// {
// 	char *ptr = NULL;
// 	int len_ft_p = ft_print_p(ptr, 0);
// 	int len_p = printf("%p", ptr);
// 	printf("%d %d", len_ft_p, len_p);
// }