#include <unistd.h>

char	str_to_rotone(char c)
{
	char rotone_str;
	if (c == 'z')
		rotone_str = c - 25;
	else
		rotone_str = c + 1;
	return (rotone_str);

}
int main(int argc, char *argv[])
{
	int	j = 0;
	char	rotone_str;

	if (argc == 2)
	{
		while (argv[1][j])
		{
		if ((argv[1][j] >= 'a' && argv[1][j] <= 'z') || \
			(argv[1][j] >= 'A' && argv[1][j] <= 'Z'))
		{
			rotone_str = str_to_rotone(argv[1][j]);
			write(1, &rotone_str, 1);
		}
		else
			write(1, &argv[1][j], 1);
		j++;
		}
	}
	write(1, "\n", 1);
}