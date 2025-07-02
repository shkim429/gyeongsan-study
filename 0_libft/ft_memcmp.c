/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 18:47:01 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/02 21:28:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	s1_tmp = (unsigned char *)s1;
	s2_tmp = (unsigned char *)s2;
	while (n--)
	{
		if (*s1_tmp != *s2_tmp)
			break ;
	}
	return (*s1_tmp - *s2_tmp);
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