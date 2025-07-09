/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:53:29 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/09 15:58:27 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	char	*s_tmp;

	s_copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	s_tmp = s_copy;
	if ((s_copy == NULL) || (s == NULL))
		return (NULL);
	while (*s)
		*s_copy++ = *s++;
	*s_copy = '\0';
	return (s_tmp);
}

// #include <stdio.h>


// int	main()
// {
// 	char	*s = ft_strdup("apple");
// 	printf("%s", );
// 	free(s);
// }

