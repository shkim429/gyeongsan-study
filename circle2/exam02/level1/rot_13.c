#include <unistd.h>

char str_to_rot13(char c)
{
	char rot_13_str;

	if (c <= 'm' || c <= 'M')
		rot_13_str = c + 13;
	else
		rot_13_str = c - 13;
	return (rot_13_str);
}

int main(int argc, char *argv[])
{
	int	j = 0;
	char rot_13_str;

	if (argc ==2)
	{
		while (argv[1][j])
		{
			if ((argv[1][j] >= 'a' && argv[1][j] <= 'z') || \
				(argv[1][j] >= 'A' && argv[1][j] <= 'Z'))
			{
				rot_13_str = str_to_rot13(argv[1][j]);
				write(1, &rot_13_str, 1);
			}
			else
				write(1, &argv[1][j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
}