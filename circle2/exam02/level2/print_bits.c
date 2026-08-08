#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	bit_len = 8;
	int	num = 0;

	num = octet - '0';
	while (bit_len--)
	{
		if (num & (1 << bit_len))
			write(1, "1", 1);
		else
			write(1, "0", 1);
	}
}

#include <stdio.h>

int main()
{
	print_bits('5');
}