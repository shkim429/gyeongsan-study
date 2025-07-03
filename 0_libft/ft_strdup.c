/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:53:29 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/03 21:10:02 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	char	*s_tmp;

	s_copy = (char *)malloc((ft_strlen(s_tmp) + 1) * sizeof(char));
	s_tmp = s_copy;
	if (s_copy == NULL)
		return (NULL);
	while (*s)
		*s_copy++ = *s++;
	*s_copy = '\0';
	return (s_tmp);
}
/*
int	main()
{
	char	s[] = "hello, world!";
	printf("%s", ft_strdup(s));
	free(s);
}
*/