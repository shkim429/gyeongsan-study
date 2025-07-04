/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:29:46 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/04 16:18:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_copy;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len > len)
		s_copy = (char *)malloc((len + 1) * sizeof(char));
	else
		s_copy = (char *)malloc((s_len + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		s_copy[i] = s[start + i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
/*
int main()
{
	char *s = "hello";
	printf("s = %s, return = %s", s,ft_substr(s, 0, 100));
}
*/