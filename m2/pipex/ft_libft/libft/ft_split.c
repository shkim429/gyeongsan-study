/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:58:15 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/22 14:20:10 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		arr_str_cnt(const char *s, char c);
int		str_len(const char *s, char c, int	*s_idx);
char	**split_calloc(char const *s, char c, int s_idx, int arr_idx);
char	*ft_strncpy(char *dest, const char *src, size_t n);

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	int		char_len;
	int		s_idx;
	int		arr_idx;
	int		start_idx;

	s_idx = 0;
	arr_idx = 0;
	split_arr = split_calloc(s, c, 0, 0);
	if (split_arr == NULL)
		return (NULL);
	while (s[s_idx])
	{
		while (s[s_idx] == c)
			s_idx++;
		if (s[s_idx] == '\0')
			break ;
		start_idx = s_idx;
		char_len = str_len(s, c, &s_idx);
		ft_strncpy(split_arr[arr_idx], s + start_idx, char_len);
		split_arr[arr_idx][char_len] = '\0';
		arr_idx++;
	}
	split_arr[arr_idx] = NULL;
	return (split_arr);
}

int	arr_str_cnt(const char *s, char c)
{
	int	i;
	int	str_cnt;

	i = 0;
	str_cnt = 0;
	if (s[0] == '\0')
		return (str_cnt);
	if (s[0] != c)
		str_cnt++;
	while (s[i])
	{
		if ((s[i] != c) && (i > 0 && (s[i - 1] == c)))
			str_cnt++;
		i++;
	}
	return (str_cnt);
}

int	str_len(const char *s, char c, int	*s_idx)
{
	int	j;
	int	char_cnt;

	j = *s_idx;
	char_cnt = 0;
	while (s[j] && s[j] != c)
		j++;
	char_cnt = j - (*s_idx);
	*s_idx = j;
	return (char_cnt);
}

char	**split_calloc(char const *s, char c, int s_idx, int arr_idx)
{
	char			**split_arr;
	const int		str_cnt = arr_str_cnt(s, c);
	int				char_len;

	split_arr = (char **)ft_calloc(str_cnt + 1, sizeof(char *));
	if (split_arr == NULL)
		return (NULL);
	while (s[s_idx])
	{
		while (s[s_idx] == c)
			s_idx++;
		if (s[s_idx] == '\0')
			break ;
		char_len = str_len(s, c, &s_idx);
		split_arr[arr_idx] = (char *)ft_calloc((char_len + 1), sizeof(char));
		if (split_arr[arr_idx] == NULL)
		{
			while (arr_idx > 0)
				free(split_arr[--arr_idx]);
			return (free(split_arr), NULL);
		}
		arr_idx++;
	}
	return (split_arr);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
