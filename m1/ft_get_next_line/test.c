#include "get_next_line.h"
#include <stdio.h>
int	test(int fd)
{
	char	buffer[BUFFER_SIZE];
	int		read_len;

	read_len = read(fd, buffer, BUFFER_SIZE);
	buffer[read_len] = '\0';
	printf("read_len: %d\n", read_len);
	printf("buffer: %s\n", buffer);
	int offset =  get_idx_find_first_chr(buffer, '\n');
	printf("offset: %d\n", offset);
	char *cutstr = ft_strcut(buffer, &offset);
	printf("cutstr: %s", cutstr);
	char *appendstr = append_str(cutstr);
	printf("appendstr: %s", appendstr);
	char buffer_str = buffer[offset];
	printf("buffer_str: %c", buffer_str);

	if (buffer[offset] != '\0')
		printf("%d", 32);
	return (1);
}
