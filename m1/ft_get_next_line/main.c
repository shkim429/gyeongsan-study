#include "get_next_line.h"

int main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd > 0)
	{
		char *str = get_next_line(fd);
		printf("%s", str);
	}
	else
		return (-1);
}
