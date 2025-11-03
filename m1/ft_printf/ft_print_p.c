/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:15:22 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/19 16:53:06 by sohuikim         ###   ########.fr       */
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
	free(str);
	return (2 + len);
}
