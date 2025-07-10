/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:58:15 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 19:58:05 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_check_sep(char sep, char c)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

int	arr_str_cnt(const char *s, char c)
{
	int	i;
	int	str_cnt;

	i = 0;
	str_cnt = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
			str_cnt++;
		i++;
	}
	return (str_cnt);
}

int	str_len(const char *s, char c, int	*s_idx)
{
	int	i;
	int	j;
	int	char_cnt;

	i = *s_idx;
	j = i;
	char_cnt = 0;
	while (s[j] != '\0' && s[j] != c)
		j++;
	char_cnt = j - i;
	if (s[j] == '\0')
		*s_idx = j;
	else
		*s_idx = j + 1;
	return (char_cnt);
}

char	**ft_malloc(char const *s, char c)
{
	char	**split_arr;
	int		str_cnt;
	int		s_idx;
	int		arr_idx;
	int		char_len;

	str_cnt = arr_str_cnt(s, c);
	split_arr = (char **)malloc((str_cnt + 1) * sizeof(char));
	if (split_arr == NULL)
		return (NULL);
	s_idx = 0;
	arr_idx = 0;
	while (s[s_idx] != '\0')
	{
		char_len = str_len(s, c, &s_idx);
		split_arr[arr_idx] = (char *)malloc((char_len + 1) * sizeof(char));
		if (split_arr[arr_idx] == NULL)
			return (NULL);
		arr_idx++;
	}
	return (split_arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	int		char_len;
	int		s_idx;
	int		arr_idx;
	int		start_idx;

	s_idx = 0;
	arr_idx = 0;
	start_idx = s_idx;
	split_arr = ft_malloc(s, c);
	if (split_arr == NULL)
		return (NULL);
	while (s[s_idx] != '\0')
	{
		start_idx = s_idx;
		char_len = str_len(s, c, &s_idx);
		ft_memcpy(split_arr[arr_idx], s + start_idx, char_len);
		split_arr[arr_idx][char_len] = '\0';
		arr_idx++;
	}
	split_arr[arr_idx] = NULL;
	return (split_arr);
}
/*
int main()
{
	char *s = "apple,banana,grape";
	char c = ',';
	int	i = 0;
	printf("%s\n", s);
	char **s_tmp = ft_split(s, c);
	
	while (s_tmp[i])
	{
		printf("%s ", s_tmp[i]);
		i++;
	}
	return (0);
}
*/