/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:52:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/27 19:40:35 by sohuikim         ###   ########.fr       */
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
			return (-1);
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
char	*update_stash(char *stash, int *offset)
{
	int	i;

	i = 0;
	while (stash[*offset] != '\0')
		stash[i++] = stash[*offset++];
	stash[i] = '\0';
	return (stash);
}

char	*ft_strcut(char *stash, int *offset)
{
	char	*cut_str;
	int		idx;
	int		cut_str_len;

	if (*offset <= 0)
		cut_str_len = ft_strlen(stash);
	idx = 0;
	if (*offset > 0)
	{
		cut_str_len = *offset - idx;
		cut_str = (char *)malloc(cut_str_len + 1);
		while (idx <= cut_str_len)
		{
			cut_str[idx] = stash[idx];
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

	cutstr_len = ft_strlen(cut_str);
	if (join_stash == NULL)
	{
		join_stash = malloc(cutstr_len);
		capacity_stash = BUFFER_SIZE;
		join_stash_end_idx = 0;
	}
	else
	{
		need_size = ft_strlen(join_stash) + cutstr_len;
		if (capacity_stash < need_size)
		{
			join_stash = ft_realloc(join_stash, capacity_stash, need_size);
			capacity_stash = need_size;
			join_stash_end_idx = ft_strlen(join_stash);
		}
	}
	i = 0;
	while (i < cutstr_len)
		join_stash[join_stash_end_idx++] = cut_str[i++];
	join_stash[join_stash_end_idx] = '\0';
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

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	int		i;

	if (s == NULL)
		return (NULL);
	s_copy = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (s_copy == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_copy[i] = s[i];
		i++;
	}
	s_copy[i] = '\0';
	return (s_copy);
}
