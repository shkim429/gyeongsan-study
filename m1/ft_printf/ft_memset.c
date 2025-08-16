/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:29:10 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/30 15:48:20 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	c_copy;
	unsigned char	*s_copy;
	size_t			i;

	c_copy = (unsigned char) c;
	s_copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s_copy[i] = c_copy;
		i++;
	}
	return (s_copy);
}
