/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:46:43 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/22 14:19:41 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;
	size_t			i;

	d_copy = (unsigned char *)dest;
	s_copy = (unsigned char *)src;
	if (n == 0)
		return (d_copy);
	i = n;
	if (d_copy > s_copy && d_copy < s_copy + n)
	{
		while (i--)
		{
			d_copy[i] = s_copy[i];
		}
	}
	else
		ft_memcpy(d_copy, s_copy, n);
	return (d_copy);
}
