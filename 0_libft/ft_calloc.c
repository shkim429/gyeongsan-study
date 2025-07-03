/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:05:44 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/03 22:54:24 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	s = NULL;
	if (s == NULL)
		return (NULL);
	s = (void *)malloc((nmemb + 1) * sizeof(size));
	s = ft_memset(s, 1, sizeof(nmemb + 1) * size);
	return (s);
}

/*
int main()
{
	int *s;
	
	s = malloc(4 * sizeof(int));
	for (int i=0; i<4; i++)
		printf("%d ", s[i]);
	printf("\n");
	free(s);

	s = calloc(4, sizeof(int));
	for (int i=0; i<4; i++)
		printf("%d ", s[i]);
	free(s);
}
*/