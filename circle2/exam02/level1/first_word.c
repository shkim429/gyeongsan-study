#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	j;

	if (argc == 2)
	{
		j = 0;
		if (argv[1][j] == 32 || argv[1][j] == 9)
		{
			j++;
			while (argv[1][j] && (argv[1][j] != 32 && argv[1][j] != 9))
			{	
				write(1, &argv[1][j], 1);
				j++;
			}
		}
	}
	write(1, "\n", 1);

}
