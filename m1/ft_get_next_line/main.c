#include "get_next_line.h"
#include "stdio.h"

int main()
{
	int		fd;
	char	*line;

	fd = open("tt.txt", O_RDONLY);
	if (fd > 0)
	{
		line = get_next_line(fd);
		printf("%s", line);
		while (line != NULL)
		{
			free(line);
			line = get_next_line(fd);
			printf("%s", line);
			// if (line == NULL)
			// 	return (write(1, "(null)", ft_strlen("(null)")));
			// else
			// 	write(1, line, ft_strlen(line));
		}
		close(fd);
		// if (line == NULL)
		// 	write(1, "(null)", ft_strlen("(null)"));
	}
	else
		return (-1);
}

