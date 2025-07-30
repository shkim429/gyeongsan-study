/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:11:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/30 17:12:25 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_id(int id)
{
	char	*str;
	int		len;

	str = ft_itoa(id);
	len = ft_strlen(str);
	return (write(1, str, len));
}
