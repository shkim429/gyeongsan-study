/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:52:49 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/19 16:53:18 by sohuikim         ###   ########.fr       */
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
