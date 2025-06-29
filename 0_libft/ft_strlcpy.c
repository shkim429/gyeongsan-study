/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:09:49 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/29 00:38:49 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;
	int	src_len;

	src_len = ft_strlen(src);
	i = 0;
	while (src[i] && size > i + 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
int main(void)
{
	char src[] = "12345";
	char dest[100] = "farefd g";
	printf("src = %s, dest = %s\n", src, dest);
	printf("src의 길이: %d", ft_strlcpy(dest, src, 1));
	printf(" dest = %s", dest);	
}
*/