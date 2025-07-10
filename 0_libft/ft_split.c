/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:29:31 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 19:40:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_check_first_str(const char *s, char c, int i)
{
	if (s[i] != c && (i == 0 || s[i - 1] == c))
		return (1);
	return (0);
}

int	is_check_end_str(const char *s, char c, int i)
{
	if ((s[i] != c && s[i + 1] == c) || s[i + 1] == '\0')
		return (1);
	return (0);
}

int	arr_str_cnt(char const *s, char c)
{
	int	i;
	int	str_cnt;

	i = 0;
	str_cnt = 0;
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
			str_cnt++;
		i++;
	}
	return (str_cnt);
}

int	str_len(char const *s, char c, int i)
{
	int	start_idx;
	int	end_idx;
	int	str;
	int	str_len;

	start_idx = 0;
	end_idx = 0;
	while (s[i] != '\0')
	{
		if (is_check_first_str(s, c, i) == 1 && str == 0)
		{
			start_idx = i;
			str = 1;
		}
		if (is_check_end_str(s, c, i) == 1 && str == 1)
		{
			end_idx = i;
			str_len = (end_idx - start_idx) + 1;
			str = 0;
		}
		i++;
	}
	return (str_len);
}

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	int		str_cnt;
	int		start_idx;
	int		end_idx;
	int		i;
	int		j;
	int		k;
	int		str;
	int		str_len;
	
	str_len = 0;
	i = 0;
	j = 0;
	k = 0;
	str_cnt = arr_str_cnt(s, c);
	split_arr = (char **)malloc((str_cnt + 1) * sizeof(char *));
	if (split_arr == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (is_check_first_str(s, c, i) && str == 0)
		{
			start_idx = i;
			str = 1;
		}
		if (is_check_end_str(s, c, i) && str == 1)
		{
			end_idx = i;
			str_len = (end_idx - start_idx) + 1;
			split_arr[j] = (char *)malloc((str_len + 1) * sizeof(char));
			k = 0;
			while (start_idx <= end_idx)
			{
				split_arr[j][k++] = s[start_idx++];
			}
			split_arr[j][k] = '\0';
			j++;
			str = 0;
		}
		i++;
	}
	split_arr[j] = NULL;
	return (split_arr);
}

int main()
{
	char *s = "apple, banana, grape";
	char c = ',';
	int	i = 0;
	printf("%s\n", s);
	char **s_tmp = ft_split(s, c);
	
	while (s_tmp[i])
	{
		printf("%s\n", s_tmp[i]);
		i++;
	}
	return (0);
}