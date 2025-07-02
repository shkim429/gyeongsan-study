/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:12:54 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/02 18:21:29 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	unsigned char	c_tmp;
	size_t			i;

	s_tmp = (unsigned char *)s;
	c_tmp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*s_tmp == c_tmp)
			return (s_tmp);
		i++;
		s_tmp++;
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
	printf("c = %d\n", c);
	printf("n = %zu\n", n);
	printf("찾은 문자 = %s", (char *)ft_memchr(s,c,n));
}
*/