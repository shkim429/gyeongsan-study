#include "libft.h"
#include <stdio.h>

char	*strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
int main()
{
	char *src = "abc";
	char dest[5];
	char *copy = NULL;

	copy = strncpy(dest, src, 3);
	printf("AAA");
	printf("%s", copy);
}