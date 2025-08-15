/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:52:49 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/15 13:43:38 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *str)
{
	int	len;

	if (str == NULL)
		return (write(1, "(null)", ft_strlen("(null)")));
	len = ft_strlen(str);
	return (write(1, str, len));
}

// #include <stdio.h>
// int main()
// {
// 	char *s = 0;
// 	ft_print_s(s);
// }

// #include <stdio.h>
// int main()
// {
// 	char *s = 0;
// 	int len_ft_s = ft_print_s(s);
// 	int len_s = printf("%s", s);
// 	printf("\n%d %d", len_ft_s, len_s);
// }