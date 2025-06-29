/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:05:51 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/29 17:32:18 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)s;
	while (n--)
	{
		*tmp++ = 0;
	}
}
/*
int main()
{
	char s[6] = "\011\0de";
	printf("%s\n", s);
	bzero(s, 2);
	for (int i=0; i<6; i++)
	{
		printf("%d ", s[i]);
	}

	printf("\n\n");
	char p[6] = "\011\0de";
	printf("%s\n",p);
	bzero(p, 2);
	for (int j=0; j<6; j++)
	{
		printf("%d ", p[j]);
	}
}
*/