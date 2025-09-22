/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:24:36 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/22 14:48:42 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	int			read_len;
	static char	*stash;

	while (read_len = read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[read_len] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
} 

void ft_strcut(char *join_stash)
{
	char	offset;
	
	if ()
}

#include <fcntl.h>
#include <unistd.h>
int main(void)
{
	int 	fd;
	char	*str;

	fd = open("temp.txt", O_RDONLY);
	str = get_next_line(fd);

	printf("%s\n", str);
	free(str);

	return (0);
}