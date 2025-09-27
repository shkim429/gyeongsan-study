/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:24:36 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/27 19:44:43 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(char *buffer);

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	int				read_len;
	static char		*stash;
	char			*line_stash;

	if (stash == NULL)
		stash = ft_strdup("");

	read_len = 1;
	while (read_len > 0)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (get_idx_find_first_chr(stash, '\n'))
			return (line_stash);
	}
	return (NULL);
}

char	*line(char *buffer)
{
	int			*offset;
	char		*cut_str;
	static char	*stash;
	char		*join_stash;

	join_stash = NULL;
	*offset = 0;
	*offset = get_idx_find_first_chr(stash, '\n');
	cut_str = ft_strcut(stash, offset);
	join_stash = append_str(cut_str);
	stash = update_stash(stash, offset);
	return (join_stash);
}
