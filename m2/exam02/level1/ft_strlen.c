int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
		len++;
	return (len);
}

#include <stdio.h>

int main()
{
	printf("%d", ft_strlen("abc"));
}