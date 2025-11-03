#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	i = 0;
	int len = (end - start) + 1;

	if (start > end)
		return (NULL);
	range = (int *)malloc(len * sizeof(int *));
	if (!range)
		return (NULL);
	while (i < len)
	{
		range[i] = start + i;
		i++;
	}
	return (range);
}

#include <stdio.h>

int main()
{
	int	*range = ft_range(1, 3);
	
	printf("%d\n", range[0]);
	printf("%d\n", range[1]);
	printf("%d\n", range[2]);
}