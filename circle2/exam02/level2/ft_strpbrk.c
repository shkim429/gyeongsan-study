#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	j = 0;
	char *s1_copy = (char *)s1;
	while (*s1)
	{
		j = 0;
		while (s2[j] && *s1_copy != s2[j])
		{
			j++;
		}
		if (*s1_copy == s2[j])
			break ;
		s1_copy++;
	}
	if (!*s1_copy)
		return (NULL);
	return (s1_copy);
}

#include <stdio.h>

int main()
{
	char *s1 = "abcdef";
	char *s2 = "fb";
	char *result = ft_strpbrk(s1, s2);

	printf("%s", result);
}