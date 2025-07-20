/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:05:44 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/13 00:05:45 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	total_size;

	total_size = nmemb * size;
	if (!size && nmemb > SIZE_MAX / size)
		return (NULL);
	s = (void *)malloc(total_size);
	if (s == NULL)
		return (NULL);
	/*
		TODO memset 함수 이해하기
	*/
	ft_memset(s, 0, total_size);
	return (s);
}
/*
#include <stdio.h>

int main()
{
	int *s;
	
	s = malloc(4 * sizeof(int));
	for (int i=0; i<4; i++)
		printf("%d ", s[i]);
	printf("\n");
	free(s);

	s = ft_calloc(4, sizeof(int));
	for (int i=0; i<4; i++)
		printf("%d ", s[i]);
	free(s);
}
*/