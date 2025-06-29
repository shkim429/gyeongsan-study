/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:29:38 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/27 20:26:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{	
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

/*
int main()
{
	int c = EOF;
	printf("before = %d", c);
	printf(" after = %d", ft_toupper(c));
}
*/