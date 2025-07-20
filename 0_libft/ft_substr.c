/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:29:46 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/13 21:40:10 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;
	size_t	s_len;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	s_copy = (char *)malloc((len + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		s_copy[i] = s[start + i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}

// #include <stdio.h>

// int main()
// {
// 	char *s = NULL;

// 	s = ft_substr("0123456789", 400, 10);
// 	printf("%s", s);
// 	free(s);
// 	return (0);
// }