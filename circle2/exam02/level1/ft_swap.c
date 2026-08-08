void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/* #include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;
	printf("original: %d %d\n", a, b);
	ft_swap(&a, &b);
	printf("swap: %d %d", a, b);
} */