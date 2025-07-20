/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:41:36 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 23:01:06 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 11:43:53 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
<<<<<<< HEAD
	write(fd, "\n", 1);
}

// int main(void)
// {
// 	ft_putendl_fd("lorem ipsum dolor sit amet", 2);
// }
=======
	write(1, "\n", 1);
}
/*
int main(void)
{
	char s[] = "hello!";
	ft_putendl_fd(s, 1);
}
*/
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
