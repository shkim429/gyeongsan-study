/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:21:41 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 15:29:35 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 13:28:26 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
<<<<<<< HEAD
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	i = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	while ((s1_copy[i] && s2_copy[i]) && i < n)
	{
		if (s1_copy[i] != s2_copy[i])
=======
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
			break ;
		i++;
	}
	if (i == n)
		return (0);
<<<<<<< HEAD
	return (s1_copy[i] - s2_copy[i]);
}

=======
	return (s1[i] - s2[i]);
}
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*
#include <stdio.h>
int main()
{
<<<<<<< HEAD
	char s1[] = "test\200"; 
	char s2[] = "test\0";

	printf("s1 = %s, s2 = %s => value: %d", s1, s2, ft_strncmp(s1, s2, 6));

=======
	char s1[] = "abcsdfwgrwgrwg"; 
	char s2[] = "abdjytjkykilul";

	printf("s1 = %s, s2 = %s => value: %d", s1, s2, ft_strncmp(s1, s2, 3));
	
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
}
*/