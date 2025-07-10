/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:38:07 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 11:26:13 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;
	size_t			i;

	d_copy = (unsigned char *)dest;
	s_copy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (d_copy);
}
/*
int main()
{
	char src1[10] = "1234567 ";
	char dest1[10] = "890";

	char src2[10] = "123";
	char dest2[10] = "456";


	printf("src1 = %s, dest1 = %s\n", src1, dest1);
	printf("src1 = %s, dest1 = %s\n\n", src1, (char *)memcpy(dest1, src1, 8));
	printf("src2 = %s, dest2 = %s\n", src2, dest2);
	printf("src2 = %s, dest2 = %s", src2, (char *)ft_memcpy(dest2, src2, 1));
}
*/