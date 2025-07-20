/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:59:12 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/07 15:51:25 by sohuikim         ###   ########.fr       */
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
	len = strlen(s1) + strlen(s2);
	join_str = (char *)malloc((len + 1) * sizeof(char));
	if (join_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join_str[i++] = s2[j++];
	join_str[i] = '\0';
	return (join_str);
}
/*
int main()
{
	char *s1 = "water";
	char *s2 = "melon";
	char *str_join = ft_strjoin(s1, s2);
	printf("s1 = %s, s2 = %s\n", s1, s2);
	printf("join_str = %s", str_join);
	free(str_join);

}
*/