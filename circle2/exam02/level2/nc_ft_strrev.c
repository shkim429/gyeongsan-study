
int	ft_strlen(char *str)
{
	int	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrev(char *str)
{
	int	str_end_idx = ft_strlen(str);
	int swap_cnt = str_end_idx / 2;
	char	tmp;
	int	i = 0;
	while (swap_cnt--)
	{
		tmp = str[i];
		str[i] = str[str_end_idx - i];
		str[str_end_idx - i] = tmp;
		i++;
	}
	return (str);
}
#include <stdio.h>

int main()
{
	char *str = "abc";
	printf("origin: %s\n", str);
	char *revstr = ft_strrev(str);
	printf("rev: %s", revstr);
}