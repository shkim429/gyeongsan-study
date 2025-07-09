#include "libft.h"

char	f(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int main()
{
	int i = 0;
	printf("%c", f(i, 'd'));
	return (0);
}