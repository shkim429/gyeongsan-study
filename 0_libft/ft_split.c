/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/07/09 17:58:15 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/13 17:55:46 by sohuikim         ###   ########.fr       */
=======
/*   Created: 2025/07/07 19:29:31 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/10 19:40:04 by sohuikim         ###   ########.fr       */
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static int	arr_str_cnt(const char *s, char c)
=======
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
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
{
	int	i;
	int	str_cnt;

	i = 0;
	str_cnt = 0;
<<<<<<< HEAD
	if (s[0] == '\0')
		return (str_cnt);
	if (s[0] != c)
		str_cnt++;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && (i > 0 && (s[i - 1] == c)))
=======
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
			str_cnt++;
		i++;
	}
	return (str_cnt);
}

<<<<<<< HEAD
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
=======
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
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
}

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
<<<<<<< HEAD
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
=======
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
>>>>>>> 64ab842c637013900c1602f397c253a28f9abaa9
