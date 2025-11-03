#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len])
		len++;
	return (len);
}

#include <stdio.h>
char	*rev_print(char *str)
{
	char *rev_str = NULL;
	int	i = 0;
	int str_end_idx = ft_strlen(str);
	printf("%d\n", str_end_idx);
	if (str_end_idx > 0)
	{
		str_end_idx -= 1;
		while (str[str_end_idx])
			rev_str[i++] = str[str_end_idx--];
		write(1, &rev_str, ft_strlen(rev_str));
	}
	else
		write(1, "", 1);
	// write(1, "\n", 1);
	return (str);
}

#include <stdio.h>
int main()
{
	char *str = "abc";
	char *result = rev_print(str);
	printf("%s", result);
}
