/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:09:49 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 12:01:56 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 13:20:30 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		src_len;

	src_len = ft_strlen(src);
	i = 0;
<<<<<<< HEAD
	if (size == 0)
		return (src_len);
=======
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
	while (src[i] != '\0' && size > i + 1)
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