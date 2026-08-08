#include <unistd.h>

int ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

#include <stdio.h>
int main(int arc, char *argv[])
{
	int	j = 0;

	int argv2_len = ft_strlen(argv[2]);
	int argv3_len = ft_strlen(argv[3]);

	if (arc == 4)
	{
		if (argv2_len != 1 || argv3_len != 1)
			return (write(1, "\n", 1));
		while (argv[1][j])
		{
			if (argv[1][j] == argv[2][0])
				argv[1][j] = argv[3][0];
			write(1, &argv[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
