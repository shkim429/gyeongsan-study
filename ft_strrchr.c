/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:54:25 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/21 19:40:40 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c_copy;
	int				i;

	c_copy = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c_copy)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	// char d = 't' + 256;
// 	// char *s = "tripouille";
// 	printf("strrchr = %s\t", strrchr("tripouille", 't' + 256));
// 	printf("ft_strrchr = %s", ft_strrchr("tripouille", 't' + 256));
// 	return (0);
// }