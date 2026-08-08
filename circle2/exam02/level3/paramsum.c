#include <unistd.h>

int main(int ac, char *av[])
{
	int	arg_cnt = 0;
	(void)av;
	if (ac < 1)
		write(1, "0", 1);
	else
	{
		arg_cnt = (ac - 1) + '0';
		write(1, &arg_cnt, 1);
	}
	write(1, "\n", 1);
}