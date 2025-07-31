/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:11:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/31 16:15:54 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_id(int id)
{
	char	*str;
	int		len;

	str = ft_itoa(id);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
