/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:52:11 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/21 19:07:11 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_check_char(char c, const char *set);
int	find_first_idx(char const *s1, char const *set);
int	find_end_idx(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_str;
	int		start_idx;
	int		end_idx;
	int		strtrim_idx;
	int		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	strtrim_idx = 0;
	start_idx = find_first_idx(s1, set);
	end_idx = find_end_idx(s1, set);
	len = (end_idx - start_idx) + 1;
	if (len < 0)
		len = 0;
	trim_str = (char *)malloc((len + 1) * sizeof(char));
	if (trim_str == NULL)
		return (NULL);
	while (start_idx <= end_idx)
	{
		trim_str[strtrim_idx++] = s1[start_idx++];
	}
	trim_str[strtrim_idx] = '\0';
	return (trim_str);
}

int	is_check_char(char c, const char *set)
{
	int	set_idx;

	set_idx = 0;
	while (set[set_idx])
	{
		if (c == set[set_idx])
			return (1);
		set_idx++;
	}
	return (0);
}

int	find_first_idx(char const *s1, char const *set)
{
	int	start_idx;

	start_idx = 0;
	while (s1[start_idx])
	{
		if (is_check_char(s1[start_idx], set) == 1)
			start_idx++;
		else
			break ;
	}
	return (start_idx);
}

int	find_end_idx(char const *s1, char const *set)
{
	int	end_idx;

	end_idx = ft_strlen(s1) - 1;
	while (end_idx >= 0)
	{
		if (is_check_char(s1[end_idx], set) == 1)
			end_idx--;
		else
			break ;
	}
	return (end_idx);
}
