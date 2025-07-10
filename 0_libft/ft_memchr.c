/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:12:54 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 11:26:52 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_copy;
	unsigned char	c_copy;
	size_t			i;

	s_copy = (unsigned char *)s;
	c_copy = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_copy[i] == c_copy)
			return (&s_copy[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char s[10] = "12345";
	int c = '2';
	size_t n = 3;
	printf("s = %s\n", s);
	printf("c = %c\n", c);
	printf("n = %zu\n", n);
	printf("찾은 문자 = %s", (char *)ft_memchr(s,c,n));
}
*/