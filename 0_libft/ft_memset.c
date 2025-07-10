/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:29:10 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 11:43:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	c_copy;
	unsigned char	*p_copy;
	size_t			i;

	i = 0;
	c_copy = (unsigned char) c;
	p_copy = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p_copy[i] = c_copy;
		i++;
	}
	return (p_copy);
}
/*
int main()
{
	char s[5];

	for (int i=0; i<5; i++)
	{
		printf("%d ", *(s + i));
	}
	printf("\n");
	memset(s, 0, sizeof(s));
	for (int i=0; i<5; i++)
	{
		printf("%d ", *(s + i));
	}
	printf("\n");
	ft_memset(s, -300, sizeof(s));
	for (int i=0; i<5; i++)
	{
		printf("%d ", *(s + i));
	}
}
*/
