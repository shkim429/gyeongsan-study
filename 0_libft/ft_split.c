/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:58:15 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/13 17:55:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_str_cnt(const char *s, char c)
{
	int	i;
	int	str_cnt;

	i = 0;
	str_cnt = 0;
	if (s[0] == '\0')
		return (str_cnt);
	if (s[0] != c)
		str_cnt++;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (i > 0 && (s[i - 1] == c)))
			str_cnt++;
		i++;
	}
	return (str_cnt);
}

static int	str_len(const char *s, char c, int	*s_idx)
{
	int	i;
	int	j;
	int	char_cnt;

	i = *s_idx;
	j = i;
	char_cnt = 0;
	while (s[j] == c)
		j++;
	while (s[j] != '\0' && s[j] != c)
		j++;
	char_cnt = j - i;
	if (s[j] == '\0')
		*s_idx = j;
	else
		*s_idx = j + 1;
	return (char_cnt);
}

static char	**split_calloc(char const *s, char c)
{
	char	**split_arr;
	int		str_cnt;
	int		s_idx;
	int		arr_idx;
	int		char_len;

	str_cnt = arr_str_cnt(s, c);
	split_arr = (char **)ft_calloc(str_cnt + 1, sizeof(char *));
	if (split_arr == NULL)
		return (NULL);
	s_idx = 0;
	arr_idx = 0;
	while (s[s_idx] != '\0')
	{
		while (s[s_idx] == c)
			s_idx++;
		char_len = str_len(s, c, &s_idx);
		split_arr[arr_idx] = (char *)ft_calloc((char_len + 1), sizeof(char));
		if (split_arr[arr_idx] == NULL)
			return (NULL);
		arr_idx++;
	}
	return (split_arr);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
	split_arr = split_calloc(s, c);
	if (split_arr == NULL)
		return (NULL);
	while (s[s_idx] != '\0')
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

// int main()
// {
// 	// char *s = "apple,banana,grape";
// 	// char c = ',';
// 	int	i = 0;
// 	// printf("%s\n", s);
// 	char **s_tmp = ft_split("chin   im   al   a" , ' ');
	
// 	while (s_tmp[i])
// 	{
// 		printf("%s\n", s_tmp[i]);
// 		free(s_tmp[i]);
// 		i++;
// 	}
// 	free(s_tmp);
// 	return (0);
// }