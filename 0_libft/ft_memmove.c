/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:46:43 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/01 18:41:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*d_tmp;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	d_tmp = d;
	if (d > s && d < s + n)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
		ft_memcpy(d, s, n);
	return (d_tmp);
}
/*
int	main()
{
	char src2[10] = "12345";
	char dest2[10] = "defghjk";

	printf("src2 = %s, dest2 = %s\n", src2, dest2);
	printf("src2 = %s, dest2 = %s\n\n", src2, (char *)memmove(dest2, src2, 5));
	printf("src2 = %p, dest2 = %p\n", src2, dest2);
}
*/