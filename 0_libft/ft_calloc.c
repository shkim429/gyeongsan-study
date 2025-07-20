/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:05:44 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/13 00:05:45 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 15:53:51 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
<<<<<<< HEAD
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
=======

	s = (void *)malloc((nmemb + 1) * sizeof(size));
	if (s == NULL)
		return (NULL);
	s = ft_memset(s, 0, sizeof(nmemb + 1) * size);
	return (s);
}

>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9

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
<<<<<<< HEAD
*/
=======
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
