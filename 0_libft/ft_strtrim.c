/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:52:11 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/07 20:03:23 by sohuikim         ###   ########.fr       */
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

	strtrim_idx = 0;
	start_idx = find_first_idx(s1, set);
	end_idx = find_end_idx(s1, set);
	len = (end_idx - start_idx) + 1;
	if (s1 == NULL || set == NULL)
		return (NULL);
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
	int	value;

	set_idx = 0;
	value = 0;
	while (set[set_idx] != '\0')
	{
		if (c == set[set_idx])
			value += 1;
		else
			value += 0;
		set_idx++;
	}
	return (value);
}

int	find_first_idx(char const *s1, char const *set)
{
	int	start_idx;

	start_idx = 0;
	while (s1[start_idx] != '\0')
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
/*
int main()
{
	char *s1 = "abc12ab123bac";
	char *set = "acb";
	char *trim_str = ft_strtrim(s1, set);
	
	printf("s1 = %s, set = %s\n", s1, set);
	printf("return = %s", trim_str);
	free(trim_str);
}
*/

