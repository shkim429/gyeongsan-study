/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:58:15 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/09 18:20:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_check_sep(char sep, char c)
{
	
}
int	arr_str_cnt(const char *s, char c)
{
	int	i;
	int	str_cnt;

	i = 0;
	str_cnt = 0;
	while (s[i] != '\0')
	{
		if ((i = 0 && s[i] != c) || (s[i - 1] == c && s[i] != c ))
			str_cnt++;
		i++;
	}
	return (str_cnt);
}
char **ft_split(char const *s, char c)
{
	
}