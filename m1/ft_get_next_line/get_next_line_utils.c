/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:52:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/25 22:04:13 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_idx_find_first_chr(char	*stash, int find_chr)
{
	int				idx;
	int				offset;
	unsigned char	find_chr_copy;

	if (stash == NULL)
		return (-1);
	idx = 0;
	find_chr_copy = (unsigned char)find_chr;
	while (stash[idx] != find_chr_copy)
	{
		if (stash[idx + 1] == '\0')
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


char	*ft_strcut(char *stash, char *buffer, int *offset)
{
	char	*cut_str;
	int		idx;

	idx = 0;
	offset = 0;
	offset = get_idx_find_first_chr(stash, "\n");
	if (offset < 0)
		return (-1);
	else if (offset == 0) // 수정 필요
		cut_str = append_str(&stash, &buffer, &offset);
	else
	{
		while (idx <= offset)
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
		reuturn (NULL);
	realloc_join_stash = ft_memcpy(realloc_join_stash, stash, capacity_stash);
}

char	*append_str(char *stash, char *buffer, int *offset)
{
	char	*join_stash;
	size_t	capacity_stash;
	size_t	need_size;
	size_t	copy_len;
	size_t	i;

	if (stash == NULL)
	{
		join_stash = malloc(ft_strlen(buffer));
		capacity_stash = BUFFER_SIZE;
	}
	else
	{
		need_size = ft_strlen(stash) + ft_strlen(buffer);
		if (capacity_stash < need_size)
			join_stash = ft_realloc(&stash, capacity_stash, need_size);
	}
	stash  = ft_strcut(&stash, &buffer, &offset);
	copy_len = offset - i;
	while (copy_len)
	{
		join_stash[]
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_copy;
	unsigned char	*s_copy;
	size_t			i;

	d_copy = (unsigned char *)dest;
	s_copy = (unsigned char *)src;

	while (i < n)
	{
		d_copy[i] = s_copy[i];
		i++;
	}
	return (d_copy);
}
