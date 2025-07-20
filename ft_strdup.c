/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:53:29 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/14 01:20:26 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 12:41:35 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	int		i;

	if (s == NULL)
		return (NULL);
	s_copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
<<<<<<< HEAD

// #include <stdio.h>


// int	main()
// {
// 	char	*s = ft_strdup(NULL);
// 	printf("%s", s);
// 	free(s);
// }
=======
/*
#include <stdio.h>


int	main()
{
	char	*s = ft_strdup("apple");
	printf("%s", s);
	free(s);
}
*/
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
