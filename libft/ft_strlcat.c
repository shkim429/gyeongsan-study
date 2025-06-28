/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:26:17 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/27 20:25:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;
	int	src_len;
	int	dst_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	while (src[i] && size -1 > dst_len + i)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < size)
	{
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}	
	else
		return (src_len + size);
}
/*
int main(void)
{
	char src[] = "67890";
	char dest[100] = "12345";
	printf("src = %s, dest = %s\n", src, dest);
	printf("길이: %d", ft_strlcat(dest, src, 10));
	printf(" dest = %s", dest);	
}
*/