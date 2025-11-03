#include <unistd.h>

char str_to_mirror(char c)
{
	char	mirror_str;
	if (c >= 'a' && c <= 'm')
		mirror_str = c + (25 - 2*(c-'a'));
	else if (c >= 'n' && c <= 'z')
		mirror_str = c - (25 -2*(c-'a'));
	else if (c >= 'A' && c <= 'M')
		mirror_str = c + (25 -2*(c-'A'));
	else
		mirror_str = c - (25 -2*(c-'A'));
	return (mirror_str);

}

int main(int argc, char *argv[])
{
	int	j = 0;
	char	mirror_str;
	if (argc == 2)
	{
		while (argv[1][j])
		{
			if ((argv[1][j] >= 'a' && argv[1][j] <= 'z') || \
				(argv[1][j] >= 'A' && argv[1][j] <= 'Z'))
			{
				mirror_str = str_to_mirror(argv[1][j]);
				write(1, &mirror_str, 1);
			}
			else
				write(1, &argv[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}
