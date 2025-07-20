/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:47:01 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 17:04:18 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 11:27:26 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			i;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
<<<<<<< HEAD
		if (s1_copy[i] != s2_copy[i])
			return (s1_copy[i] - s2_copy[i]);
		i++;
	}
	return (0);
=======
		if (*s1_copy != *s2_copy)
			break ;
	}
	return (*s1_copy - *s2_copy);
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
}
/*
int main()
{
<<<<<<< HEAD
	char s1[10] = "abcdefgh";
	char s2[10] = "abcdwxyz";

	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("ft_memcmp의 return: %d\n", ft_memcmp(s1, s2, 6));
	printf("memcmp의 return: %d\n", memcmp(s1, s2, 6));

=======
	char s1[10] = "abcdefg";
	char s2[10] = "bddefg";

	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("return: %d", ft_memcmp(s1, s2, 1));
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
}
*/