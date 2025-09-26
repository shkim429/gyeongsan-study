#include "get_next_line.h"

int main()
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	if (fd > 0)
		test(fd);
	else
		return (-1);
}
