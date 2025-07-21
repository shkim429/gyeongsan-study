/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:38:07 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/14 18:58:29 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (dest);
	if (n == 0)
		return (dest);
	d_copy = (unsigned char *)dest;
	s_copy = (unsigned char *)src;
	if (d_copy > s_copy && d_copy < s_copy + n)
		return (d_copy);
	i = 0;
	while (i < n)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (d_copy);
}
