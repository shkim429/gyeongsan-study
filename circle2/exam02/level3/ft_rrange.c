#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int *rrange;
	int	i = 0;
	int	len = (end - start) + 1;

	if (start > end)
		return (NULL);
	rrange = (int *)malloc(len * sizeof(int));
	if (!rrange)
		return (NULL);

	while (i < len)
	{
		rrange[i] = end - i; 
		i++; 
	}
	return (rrange);
}
#include <stdio.h>

int main()
{
	int	*rrange = ft_rrange(-1, 2);
	
	printf("%d\n", rrange[0]);
	printf("%d\n", rrange[1]);
	printf("%d\n", rrange[2]);
}