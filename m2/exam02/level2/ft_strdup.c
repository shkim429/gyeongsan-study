#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int	i = 0;
	dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
int main()
{
	char *s = "abc";
	char *dest = ft_strdup(s);
	printf("%s", dest);
	free(dest);
}