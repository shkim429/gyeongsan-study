#include "get_next_line.h"
#include <stdio.h>
char *buffer[BUFFER_SIZE];

int	test(int fd)
{
	int read_len = read(fd, buffer, BUFFER_SIZE);
	printf("%d", read_len);
	return (read_len);

}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	if (fd > 0)
	 test(fd);
	return (0);
}
