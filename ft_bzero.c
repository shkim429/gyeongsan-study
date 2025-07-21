/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:05:51 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/21 19:31:17 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s_copy;
	size_t			i;

	i = 0;
	s_copy = (unsigned char *)s;
	while (i < n)
	{
		s_copy[i] = 0;
		i++;
	}
}
