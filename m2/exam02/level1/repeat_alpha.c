#include <unistd.h>

int main(int arc, char *argv[])
{
	int	j = 0;
	int alpha_idx = 0;
	if (arc == 2)
	{
		while (argv[1][j])
		{
			if ((argv[1][j] >= 'a' && argv[1][j] <= 'z') || \
				(argv[1][j] >= 'A' && argv[1][j] <= 'Z'))
			{
				alpha_idx = argv[1][j] - 'a' + 1;
				while (alpha_idx--)
					write(1, &argv[1][j], 1);
			}
			else
				write(1, &argv[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
