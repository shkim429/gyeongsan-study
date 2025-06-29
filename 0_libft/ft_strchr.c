/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:12:42 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/28 17:17:28 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
//	if (c == '\0')
//		return ("\0");
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
int main()
{
	char d = '2';
	char *s = "abcde";
	printf("strchr = %s", strchr("abcde", '\0'));
	printf("%c\n", d);
	printf("ft_strchr = %s", ft_strchr("abcde", '\0'));
	printf("%c", d);
}
