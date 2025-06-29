/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:54:25 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/28 17:19:44 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	while (i > 0)
	{
		if (*s == c)
			return ((char *) s);
		i--;
		s--;
	}
	return (NULL);
}

/*
int main()
{
	char d = '2';
	char *s = "abcde";
	printf("strrchr = %s", strrchr("abcde", '\0'));
	printf("%c\n", d);
	printf("ft_strrchr = %s", ft_strrchr("abcde", '\0'));
	printf("%c", d);
}
*/
