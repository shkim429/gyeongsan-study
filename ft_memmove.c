/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:46:43 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/14 00:23:12 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 11:35:56 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
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
<<<<<<< HEAD
	if (n == 0)
		return (d_copy);
	i = n;
	if (d_copy > s_copy && d_copy < s_copy + n)
	{
		while (i--)
		{
			d_copy[i] = s_copy[i];
=======
	i = 0;
	if (d_copy > s_copy && d_copy < s_copy + n)
	{
		while (i < n)
		{
			d_copy[i] = s_copy[i];
			i++;
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
		}
	}
	else
		ft_memcpy(d_copy, s_copy, n);
	return (d_copy);
}

<<<<<<< HEAD
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// int	main()
// {
// // 	// char src2[10] = "12345 ";
// // 	// char dest2[10] = "defghjk";

// 	char str[30] = "lorem ipsum dolor sit amet";
// 	char *src = str;
// 	char *dest = str + 1;
// 	//printf("src = %s, fdest = %s\n", src, (char *)memmove(dest, src, 8));
// 	printf("ft_src = %s, ft_dest = %s\n", src, (char *)ft_memmove(dest, src, 8));

// // char str[30] = "abcd";
// // char *src = str;
// // char *dest = str + 4;
// // printf("src의 주소 = %p dest의 주소 = %p\n", src, dest);


// }
=======
int	main()
{
	char src2[10] = "12345 ";
	char dest2[10] = "defghjk";

	printf("src2 = %s, dest2 = %s\n", src2, dest2);
	printf("src2 = %s, dest2 = %s\n", src2, (char *)memmove(dest2, src2, 6));
	printf("src2 = %p, dest2 = %p\n", src2, dest2);
	printf("ft_src2 = %s, ft_dest2 = %s\n", src2, (char *)ft_memmove(dest2, src2, 6));

	
}
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
