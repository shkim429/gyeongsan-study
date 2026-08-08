#include <unistd.h>

void ft_itoa(int num)
{
	char char_num;

	if (num > 9)
	{
		char_num = (num/10) + '0';
		write(1, &char_num, 1);
	}
	char_num = (num%10) + '0';
	write(1, &char_num, 1);
}

int main()
{
	int num = 1;

	while (num <= 100)
	{
		if (num % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (num % 5 == 0)
			write(1, "buzz", 4);
		else if (num % 3 == 0)
			write(1, "fizz", 4);
		else
			ft_itoa(num);
		write(1, "\n", 1);
		num++;
	}
}


