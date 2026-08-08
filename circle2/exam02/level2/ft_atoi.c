int	ft_atoi(char *str)
{
	int sign = 1;
	int	i = 0;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] == '-' || str[i] == '+')
		i++;
		
}