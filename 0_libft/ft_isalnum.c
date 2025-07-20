/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:10:58 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 11:28:18 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/06/27 20:24:53 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/*
int main()
{
	int c;
	printf("한 문자 입력 >> ");
	scanf("%d", &c);
	printf("%d\n", ft_isalnum(c));
}
*/