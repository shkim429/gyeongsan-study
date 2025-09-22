/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 14:52:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/22 22:23:50 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_idx_find_first_chr(char	*join_stash, int find_chr)
{
	int				idx;
	int				offset;
	unsigned char	find_chr_copy;

	if (join_stash == NULL)
		return (NULL);
	idx = 0;
	find_chr_copy = (unsigned char)find_chr;
	while (join_stash[idx] != find_chr_copy)
	{
		if (join_stash[idx] == '\0')
			return (0);
		idx++;
	}
	offset = idx + 1;
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

void	*ft_memset(void *str, int init_value, size_t size)
{
	unsigned char	*str_copy;
	unsigned char	init_value_copy;
	size_t			i;

	str_copy = (unsigned char *) str_copy;
	init_value_copy = (unsigned char) init_value_copy;
	i = 0;
	while (i < size)
	{
		str_copy[i] = init_value_copy;
		i++;
	}
	return (str_copy);
}

char	*ft_strdup(char *str)
{
	char	*str_copy;
	int		i;

	if (str == NULL)
		return (NULL);
	str_copy = (char *)malloc(ft_strlen(str) * sizeof(char));
	if (str_copy == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_copy[i] = str[i];
		i++;
	}
	str_copy[i] = '\0';
	return (str_copy);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*str;
	size_t	total_size;

	if (size != 0 && nmeb > SIZE_MAX / size)
		return (NULL);
	str = (void *)malloc(total_size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, total_size);
	return (str);
}

char	*ft_strcut(char *join_stash, int *offset)
{
	char	*line;
	int		idx;

	idx = 0;
	offset = 0;
	offset = get_idx_fid_first_chr(join_stash, "\n");
	if (offset < 0)
		return (-1);
	else if (offset == 0)
		line = ft_strudp("");
	else
	{
		line = (char *)ft_calloc((offset - idx), sizeof(char));
		while (idx <= offset)
		{
			line[idx] = join_stash[idx];
			idx++;
		}
	}
	return (line);
}



void	*ft_memcpy(char *old_join_stash, char *new_join_stash, int *offset)
{
	unsigned char	*old_join_stash_copy;
	unsigned char	*new_join_stash_copy;

	old_join_stash_copy = (unsigned char *)old_join_stash;
	new_join_stash_copy = (unsigned char *)new_join_stash;
	
	while (old_)
}
