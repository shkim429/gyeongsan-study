#include <stdlib.h>
#include <unistd.h>

int main(int ac, char *av[])
{
	int j = 0;
	int start = 0;
	int end = 0;
	if (ac == 2)
	{
		while (av[1][j])
			j++;
		while (j >= 0)
		{
			while (av[1][j] == '\0' || av[1][j] == ' ' || av[1][j] == '\t')
				j--;
			end = j;
			while (av[1][j] && av[1][j] != ' ' && av[1][j] != '\t')
				j--;
			start = j + 1;

			int flag;
			flag = start;
			while (start <= end)
			{
				write(1, &av[1][start], 1);
				start++;
			}
			if (flag != 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
}