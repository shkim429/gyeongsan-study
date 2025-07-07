/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:29:31 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/07 20:09:19 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_check_sep(char const *s, char c)
{
	int	i;
	int	value = 0;

	i = 0;
	value = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			value += 1;
		else
			value += 0;
		i++;
	}
	return (value);
}
char	**ft_split(char const *s, char c)
{
	
}