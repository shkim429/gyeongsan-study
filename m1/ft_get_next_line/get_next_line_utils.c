/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:52:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/26 22:13:37 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_idx_find_first_chr(char	*buffer, int find_chr)
{
	int				idx;
	int				offset;
	unsigned char	find_chr_copy;

	if (buffer == NULL) // 검토 필요(read() 호출 직후, 에러인지 확인해도 될 것 같음)
		return (-1);
	idx = 0;
	find_chr_copy = (unsigned char)find_chr;
	while (buffer[idx] != find_chr_copy)
	{
		if (buffer[idx] == '\0')
			break ;
		idx++;
	}
	offset = idx;
	return (offset);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}


char	*ft_strcut(char *buffer, int *offset)
{
	char	*cut_str;
	int		idx;
	int		cut_str_len;

	if (*offset < 0)
		return (NULL);
	idx = 0;
	*offset = 0;
	*offset = get_idx_find_first_chr(buffer, '\n'); // 수정 필요: 호출하는 쪽에서 offset 계산
	cut_str_len = *offset - idx;
	cut_str = (char *)malloc(cut_str_len + 1);
	if (*offset == 0) // 수정 필요
		cut_str = ""; // 빈 문자열 동적 할당
	else
	{
		while (idx <= cut_str_len)
		{
			cut_str[idx] = buffer[idx];
			idx++;
		}
	}
	cut_str[idx] = '\0';
	return (cut_str);
}

char	*ft_realloc(char *stash, size_t capacity_stash, size_t need_size)
{
	char	*realloc_join_stash;

	realloc_join_stash = malloc(need_size);
	if (realloc_join_stash == NULL)
		return (NULL);
	realloc_join_stash = ft_memcpy(realloc_join_stash, stash, capacity_stash);
	free(stash);
	return (realloc_join_stash);
}

char	*append_str(char *cut_str)
{
	static char			*join_stash;
	static size_t		capacity_stash;
	size_t				need_size;
	int					join_stash_end_idx;
	size_t				cutstr_len;
	size_t				i;

	if (join_stash == NULL) // 수정 필요: 초기값으로 NULL이 안 들어오는 경우도 있을 것 같음
	{
		join_stash = malloc(ft_strlen(cut_str));
		capacity_stash = BUFFER_SIZE;
		join_stash = cut_str;
		join_stash_end_idx = 0;
	}
	else
	{
		cutstr_len = ft_strlen(cut_str);
		need_size = ft_strlen(join_stash) + cutstr_len;
		if (capacity_stash < need_size)
		{
			join_stash = ft_realloc(join_stash, capacity_stash, need_size); // i) t = abc\ndb  => abc
			capacity_stash = need_size;
			join_stash_end_idx = ft_strlen(join_stash);
			i = 0;
			while (i <= cutstr_len)
				join_stash[join_stash_end_idx++] = cut_str[i++];
			join_stash[join_stash_end_idx] = '\0';
		}
	}
	return (join_stash);
}



void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;
	size_t			i;

	i = 0;
	d_copy = (unsigned char *)dest;
	s_copy = (unsigned char *)src;

	while (i < n)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (d_copy);
}
