#include "get_next_line.h"
#include "stdio.h"

int main()
{
	int		fd;
	char	*line;

	// fd = 1000;
	fd = open("errorCase1.txt", O_RDONLY);
	if (fd > 0)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(fd);
			printf("%s\n", line);
		}
		close(fd);
	}
	else
		return (-1);
}

