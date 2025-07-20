/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 20:29:08 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 05:16:38 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/06/28 10:50:21 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
<<<<<<< HEAD
		c = c + 32;
	return (c);
=======
	{
		c = c + 32;
		return (c);
	}
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
}
/*
#include <stdio.h>

int main()
{
	int c = 'd';
	printf("before = %d", c);
	printf(" after = %d", ft_tolower(c));
}
*/
