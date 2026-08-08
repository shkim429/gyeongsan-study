#include <unistd.h>

char	*check_double_str(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == 1)
			i++;
		j = i + 1;
		while (str[j])
		{	
			if (str[j] == 1)
				j++;
			if (str[i] == str[j])
				str[j] = '1';
			j++;
		}
		i++;
	}
	return (str);
}

int main(int argc, char *argv[])
{
	int	i;
	int	j;
	char *str_without_double;

	if (argc == 3)
	{
		i = 0;
		str_without_double = check_double_str(argv[1]);
		while (str_without_double[i])
		{
			j = i;
			while (argv[2][j])
			{
				if (str_without_double[i] == argv[2][j])
				{
					write(1, &str_without_double[i], 1);
					break ;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
