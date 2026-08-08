#include <unistd.h>

int main(int argc, char *argv[])
{
	int	j = 0;
	char ulc;
	if (argc == 2)
	{
		while (argv[1][j])
		{
			if (argv[1][j] >= 'a' && argv[1][j] <= 'z')
				ulc = argv[1][j] - 32;
			else if (argv[1][j] >= 'A' && argv[1][j] <= 'Z')
				ulc = argv[1][j] + 32;
			else
				ulc = argv[1][j];
			write(1, &ulc, 1);
			j++;
		}
	}
	write(1, "\n", 1);
}