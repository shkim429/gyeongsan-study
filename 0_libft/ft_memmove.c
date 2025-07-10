/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:46:43 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 11:35:56 by sohuikim         ###   ########.fr       */
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
	i = 0;
	if (d_copy > s_copy && d_copy < s_copy + n)
	{
		while (i < n)
		{
			d_copy[i] = s_copy[i];
			i++;
		}
	}
	else
		ft_memcpy(d_copy, s_copy, n);
	return (d_copy);
}

int	main()
{
	char src2[10] = "12345 ";
	char dest2[10] = "defghjk";

	printf("src2 = %s, dest2 = %s\n", src2, dest2);
	printf("src2 = %s, dest2 = %s\n", src2, (char *)memmove(dest2, src2, 6));
	printf("src2 = %p, dest2 = %p\n", src2, dest2);
	printf("ft_src2 = %s, ft_dest2 = %s\n", src2, (char *)ft_memmove(dest2, src2, 6));

	
}
