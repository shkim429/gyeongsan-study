/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:46:43 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/14 00:10:54 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_copy;
	const unsigned char	*s_copy;
	size_t			i;

	d_copy = (unsigned char *)dest;
	s_copy = (const unsigned char *)src;
	if (n == 0)
		return (d_copy);
	i = n;
	if (d_copy > s_copy && d_copy < s_copy + n)
	{
		while (i--)
		{
			d_copy[i] = s_copy[i];
		}
	}
	else
		ft_memcpy(d_copy, s_copy, n);
	return (d_copy);
}

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int	main()
{
// 	// char src2[10] = "12345 ";
// 	// char dest2[10] = "defghjk";

	char str[30] = "lorem ipsum dolor sit amet";
	char *src = str;
	char *dest = str + 1;
	//printf("src = %s, fdest = %s\n", src, (char *)memmove(dest, src, 8));
	printf("ft_src = %s, ft_dest = %s\n", src, (char *)ft_memmove(dest, src, 8));

// char str[30] = "abcd";
// char *src = str;
// char *dest = str + 4;
// printf("src의 주소 = %p dest의 주소 = %p\n", src, dest);


}