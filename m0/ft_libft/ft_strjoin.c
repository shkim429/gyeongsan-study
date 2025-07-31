/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:59:12 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/22 14:20:33 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	int		i;
	int		j;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc((len + 1) * sizeof(char));
	if (join_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		join_str[i++] = s2[j++];
	join_str[i] = '\0';
	return (join_str);
}
