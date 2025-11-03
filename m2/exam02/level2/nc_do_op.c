#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int get_calculate(int num1, int num2, char op)
{
	int calcul_num = 0;
	if (op == '+')
		calcul_num = num1 + num2;
	else if (op == '-')
		calcul_num = num1 - num2;
	else if (op == '*')
		calcul_num = num1 * num2;
	else if (op == '/')
		calcul_num = num1 / num2;
	else if (op == '%')
		calcul_num = num1 % num2;
	return (calcul_num);
}

int is_check_erro_input(char *str1, char *str2, char *op)
{
	int	i =0;
	while (str1[i])
	{
		if ((!(str1[i] >= '0' && str1[i] <= '9') || \
			(str1[i] != '-' || str1[i] != '+')))
			return (1);
		i++;
	}
	i = 0;
	while (str2[i])
	{
		if ((!(str2[i] >= '0' && str2[i] <= '9')) || \
			(str2[i] != '-' || str2[i] != '+'))
			return (1);
		i++;
	}
	i = 0;
	if (!(op[1]) && op[0] != '+' && op[0] != '-' && \
		op[0] != '*' && op[0] != '/' && op[0] != '%')
		return (1);

	return (0);
}

int	main(int argc, char *argv[])
{
	int	num1;
	int	num2;
	int	calcul_num;

	if (argc == 4)
	{
		if (is_check_erro_input(argv[1], argv[2], argv[3]) == 1)
		{
			printf("1");
			write(1, "\n", 1);
		}
		return (0);
		num1 = atoi(argv[1]);
		num2 = atoi(argv[3]);
		printf("num2: %d", num2);
		calcul_num = get_calculate(num1, num2, argv[3][0]);
		printf("%d", calcul_num);
	}
	write(1, "\n", 1);
}



