int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	num = 0;
	int	base_num_result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			num = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			num = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = str[i] - 'A' + 10;
		else
			break ;
		base_num_result = base_num_result * str_base + num;
		i++;
	}
	return (base_num_result * sign);
}

#include <stdio.h>
int main()
{
	int result = ft_atoi_base("42", 16);
	printf("%d", result);
}