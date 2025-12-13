/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:11:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/19 16:53:10 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_id(int id_num)
{
	char	*str;
	int		len;

	str = ft_itoa(id_num);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
