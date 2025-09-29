/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:24:36 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/30 04:54:29 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *buffer);

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	int				read_len;
	static char		*stash;
	char			*line;

	if (stash == NULL)
		stash = ft_strdup("");
	line = NULL;
	read_len = 1;
	while (1)
	{
		if (get_idx_find_first_chr(stash, '\n'))
			return (line = make_line(stash));
		if (read_len < 0)
			return (free(stash), NULL);
		if (read_len == 0)
		{
			line = make_line(stash);
			return (end_get_next_line(line, stash));
		}
		read_len = read(fd, buffer, BUFFER_SIZE);
		buffer[read_len] = '\0';
		stash = append_str(stash, buffer);
	}
	return (line);
}

char	*make_line(char *stash)
{
	int			offset;
	char		*cut_str;

	offset = 0;
	offset = get_idx_find_first_chr(stash, '\n');
	cut_str = ft_strcut(stash, &offset);
	stash = update_stash(stash, &offset);
	return (cut_str);
}

char	*ft_strcut(char *stash, int *offset)
{
	char	*cut_str;
	int		idx;
	int		cut_str_len;

	idx = 0;
	if (*offset <= 0)
	{
		cut_str_len = ft_strlen(stash);
		*offset = cut_str_len;
	}
	if (*offset > 0)
		cut_str_len = *offset + 1;
	cut_str = (char *)malloc(cut_str_len + 1);
	while (idx < cut_str_len)
	{
		cut_str[idx] = stash[idx];
		idx++;
	}
	cut_str[idx] = '\0';
	return (cut_str);
}

char	*append_str(char *pre_stash, char *cut_str)
{
	char				*join_stash;
	size_t				need_capacity;
	int					join_stash_end_idx;
	size_t				cutstr_len;
	size_t				i;

	join_stash = NULL;
	cutstr_len = ft_strlen(cut_str);
	need_capacity = ft_strlen(pre_stash) + cutstr_len;
	join_stash = ft_remalloc(pre_stash, need_capacity);
	join_stash_end_idx = ft_strlen(join_stash);
	i = 0;
	while (i < cutstr_len)
		join_stash[join_stash_end_idx++] = cut_str[i++];
	join_stash[join_stash_end_idx] = '\0';
	return (join_stash);
}

char	*end_get_next_line(char *line, char *stash)
{
	if (*line != '\0')
		return (line);
	else
	{
		free(line);
		free(stash);
		return (NULL);
	}
}
