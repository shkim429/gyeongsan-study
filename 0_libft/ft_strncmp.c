/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 21:21:41 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/12 15:29:35 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	i = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	while ((s1_copy[i] && s2_copy[i]) && i < n)
	{
		if (s1_copy[i] != s2_copy[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return (s1_copy[i] - s2_copy[i]);
}

/*
#include <stdio.h>
int main()
{
	char s1[] = "test\200"; 
	char s2[] = "test\0";

	printf("s1 = %s, s2 = %s => value: %d", s1, s2, ft_strncmp(s1, s2, 6));

}
*/