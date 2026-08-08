#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
	{
		len++;
	}
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/* int main()
{
	ft_putstr("abc");
} */

