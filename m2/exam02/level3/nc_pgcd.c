#include <stdlib.h>
#include <stdio.h>

int main(int ac, char *av[])
{
	int	num1;
	int	num2;
	int	r;

	if (ac == 3)
	{
		num1 = atoi(av[1]);
		num2 = atoi(av[2]);
		while (num2 != 0)
		{
			r = num1 % num2;
			num1 = num2;
			num2 = r;
		}
		printf("%d", num1);
	}
	printf("\n");
}
