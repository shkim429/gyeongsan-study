unsigned int	get_gcd(unsigned int a, unsigned int b)
{
	int	r;

	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return (a);
}
unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	result = 0;
	int	gcd = get_gcd(a, b);

	result = (a * b) / gcd;
	return (result);
}

#include <stdio.h>

int main()
{
	unsigned int a = 50; 
	unsigned int b = 30;

	unsigned int result = lcm(a, b);
	printf("%d", result);
}