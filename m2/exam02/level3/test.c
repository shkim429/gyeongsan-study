#include <unistd.h>

int ft_atoi(char *str)
{
	int	i = 0;
	int	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num > 9)
	{
		ft_putnbr(num / 10);
		ft_putchar((num % 10) + '0');
	}
}

int main(int ac, char *av[])
{
	int	i = 1;
	int	num_av = 0;
	if (ac != 2)
		write(1, "\n", 1);
	else
	{
		num_av = ft_atoi(av[1]);
		while (i < 10)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num_av);
			write(1, " = ", 3);
			ft_putnbr(i * num_av);
			write(1, "\n", 1);
			i++;
		}
	}
}



