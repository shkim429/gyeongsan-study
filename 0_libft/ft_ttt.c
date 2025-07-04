#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	ft_putchar_fd(n % 10 + '0', fd);
}

int main()
{
	// ft_putnbr_fd(-2147483648, 1);
	printf("\n");
	ft_putnbr_fd(0, 1);
}