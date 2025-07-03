/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:31:05 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/03 17:49:36 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*little_tmp;
	const char	*big_tmp;

	little_tmp = little;
	if (*little == '\0')
		return ((char *)big);
	while (*big && len--)
	{
		big_tmp = big;
		while (*big == *little)
		{
			if (*(little + 1) == '\0')
				return ((char *)big_tmp);
			big++;
			little++;
		}
		big++;
		little = little_tmp;
	}
	return (NULL);
}
/*
#include <string.h>
int main()
{
	char big[26] = "selensele";
	char little[6] = "le";
	size_t len = 2;
	printf("%s\n", ft_strnstr(big, little, len));
}
*/