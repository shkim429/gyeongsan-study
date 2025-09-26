/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:24:36 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/26 17:39:53 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line(char *buffer);

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	int				read_len;
	static char		*line_stash;

	while ((read_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_len] = '\0';
		if (get_idx_find_first_chr(line_stash, '\n'))
			break ;
		else
		{
			line_stash = line(buffer);
		}
		return (line_stash);
	}
	return (line_stash);
}



	// read_len > 0 보다 크면 한 줄 단위 데이터로 가공, 이때, 읽기는 offset이 버퍼 끝에 도달했을 때만(그전까지는 읽지 않기)
	// offset이 buffer 끝에 도달하면 read 반복

char	*line(char *buffer)
{
	int		offset;
	char 	*cut_str;
	char	*join_stash;
	
	join_stash = NULL;
	offset = 0;
	if (get_idx_find_first_chr(join_stash, '\n') != 0)
	{
		cut_str = ft_strcut(buffer, &offset);  // i) abc
		join_stash = append_str(cut_str, &offset); // i) abc
	}
	return (join_stash);
}

// void ft_strcut(char *join_stash)
// {
// 	char	offset;
	
// 	if ()
// }

// #include <fcntl.h>
// #include <unistd.h>
// int main(void)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open("test.txt", O_RDONLY);
// 	str = get_next_line(fd);

// 	printf("%s\n", str);
// 	free(str);

// 	return (0);
// }