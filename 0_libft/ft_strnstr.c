/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:31:05 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 18:39:12 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 15:19:55 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
<<<<<<< HEAD
=======
	j = 0;
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
<<<<<<< HEAD
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
=======
		while (big[i] == little[j])
		{
			if (little[i + 1] == '\0')
				return ((char *)&big[i]);
			i++;
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
int main()
{
<<<<<<< HEAD
	char big[26] = "lensele";
	char little[6] = "el";
	size_t len = 5;
=======
	char big[26] = "selensele";
	char little[6] = "le";
	size_t len = 6;
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
	printf("%s\n", ft_strnstr(big, little, len));
}
*/