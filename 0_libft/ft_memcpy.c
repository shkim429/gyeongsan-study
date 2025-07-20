/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:38:07 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/14 01:33:13 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 11:26:13 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
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
<<<<<<< HEAD
	if (d_copy > s_copy && d_copy < s_copy + n)
		return (d_copy);
=======
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
	i = 0;
	while (i < n)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (d_copy);
}
<<<<<<< HEAD

// int main()
// {
// 	char src1[10] = "1234567 ";
// 	char dest1[10] = "1234567 ";

// 	char src2[10] = "123";
// 	char dest2[10] = "456";

// 	char str[30] = "abcd";
// 	char *src3 = str;
// 	char *dest3 = str;
// 	printf("src1 = %s, dest1 = %s\n", src1, dest1);
// 	printf("src1 = %s, dest1 = %s\n\n", src1, (char *)memcpy(dest1, src1, 8));
// 	printf("src2 = %s, dest2 = %s\n", src2, dest2);
// 	printf("src2 = %s, dest2 = %s\n", src2, (char *)ft_memcpy(dest2, src2, 1));
// 	printf("src3 = %s, dest3 = %s\n", src3, (char *)ft_memcpy(dest3, src3, 0));
// 	// printf("src3 = %p, dest3 = %p\n", src3, dest3);

// }
=======
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
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
