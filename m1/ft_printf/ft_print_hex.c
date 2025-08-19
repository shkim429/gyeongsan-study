/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 14:22:50 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/19 18:54:21 by sohuikim         ###   ########.fr       */
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
