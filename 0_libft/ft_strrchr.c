/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:54:25 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/13 05:13:32 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 15:23:53 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
<<<<<<< HEAD
	unsigned char	c_copy;
	int				i;

	c_copy = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c_copy)
=======
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if (s[i] == c)
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
<<<<<<< HEAD
// int main()
// {
// 	// char d = 't' + 256;
// 	// char *s = "tripouille";
// 	printf("strrchr = %s\t", strrchr("tripouille", 't' + 256));
// 	printf("ft_strrchr = %s", ft_strrchr("tripouille", 't' + 256));
// 	return (0);
// }
=======
/*
int main()
{
	char d = 'd';
	char *s = "abcde";
	printf("strrchr = %s\t", strrchr(s, d));
	printf("ft_strrchr = %s", ft_strrchr(s, d));
}
*/
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
