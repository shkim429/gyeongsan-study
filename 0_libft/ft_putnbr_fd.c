/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 18:52:44 by sohuikim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/07/12 05:55:09 by sohuikim         ###   ########.fr       */
=======
/*   Updated: 2025/07/10 11:47:46 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
<<<<<<< HEAD
/*
=======

>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
int main()
{
	ft_putnbr_fd(2147483648, 1);
	printf("\n");
	ft_putnbr_fd(-3, 1);
	printf("\n");
	ft_putnbr_fd(0, 1);
}
<<<<<<< HEAD
*/
=======
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
