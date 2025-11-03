#include <unistd.h>

int	ft_atoi(char *str)
{
	int	i = 0;
	int	num = 0;

	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}	

void print_hex(int num)
{
	char hex_table[] = "0123456789abcdef";
	if (num >= 16)
		print_hex(num/16);
	write(1, &hex_table[num%16], 1);
}

int	main(int ac, char *av[])
{
	int	num;

	if (ac == 2)
	{
		num = ft_atoi(av[1]);
		print_hex(num);
	}
	write(1, "\n", 1);
}
