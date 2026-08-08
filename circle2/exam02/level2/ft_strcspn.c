#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	// int	cnt = 0;
	int	i = 0;
	int	j = 0;

	while (s[i])
	{
		j = 0;
		while (reject[j] && s[i] != reject[j])
			j++;
		if (s[i] == reject[j])
			break ;
		i++;
	}
	return (i);
}

#include <stdio.h>

int main()
{
	char *s = "abcd123";
	char *reject = "0123456789";
	int cnt = ft_strcspn(s, reject);
	printf("%d", cnt);
}