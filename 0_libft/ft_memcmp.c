/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:47:01 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 11:27:26 by sohuikim         ###   ########.fr       */
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
		if (*s1_copy != *s2_copy)
			break ;
	}
	return (*s1_copy - *s2_copy);
}
/*
int main()
{
	char s1[10] = "abcdefg";
	char s2[10] = "bddefg";

	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("return: %d", ft_memcmp(s1, s2, 1));
}
*/