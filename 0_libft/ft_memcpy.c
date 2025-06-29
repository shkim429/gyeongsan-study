/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:38:07 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/29 22:33:12 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s; 

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (d);
}

int main()
{
	char src1[32] = "Source memory";
	char dest1[32] = "Destination memory";

	// char src2[15] = "12345678";
	// char dest2[15] = "99999999";

	printf("src1 = %s, dest1 = %s\n", src1, dest1);
	printf("src1 = %s, dest1 = %s", src1, (char *)memcpy(dest1, src1, sizeof(src1)));
	// printf("src2 = %s, dest2 = %s\n", src2, dest2);
	// printf("src2 = %s, dest2 = %s", src2, ft_memcpy(dest2, src2, sizeof(src2)));
}