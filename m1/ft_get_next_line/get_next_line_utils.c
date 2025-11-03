/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:52:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/10/03 04:19:39 by sohuikim         ###   ########.fr       */
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
		if (stash[idx] == '\0')
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
		stash[i++] = stash[++(*offset)];
	stash[i] = '\0';
	*offset = 0;
	return (stash);
}

char	*ft_remalloc(char *stash, size_t need_capacity)
{
	char	*remalloc_join_stash;
	int		copy_len;
	int		i;

	remalloc_join_stash = (char *)malloc(need_capacity + 1);
	if (remalloc_join_stash == NULL)
		return (NULL);
	copy_len = ft_strlen(stash) + 1;
	i = 0;
	while (i < copy_len)
	{
		remalloc_join_stash[i] = stash[i];
		i++;
	}
	free(stash);
	return (remalloc_join_stash);
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
