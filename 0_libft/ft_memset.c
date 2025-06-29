/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:29:10 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/29 22:00:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	tmp;
	unsigned char	*p;

	tmp = (unsigned char) c;
	p = (unsigned char *)s;
	while (n--)
		*p++ = tmp;
	return (p);
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
	memset(s, -300, sizeof(s));
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