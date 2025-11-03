#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	int	i;
	int	num_av;
	if (ac == 2)
	{
		i = 1;
		num_av = atoi(av[1]);
		if (num_av == 1)
			printf("1");
		while (++i <= num_av)
		{
			if (num_av % i == 0)
			{
				printf("%d", i);
				if (num_av == i)
					break ;
				printf("*");
				num_av /= i;
				i = 1;
			}
		}
	}	
	printf("\n");
}