#include <stdio.h>

int	numarr_len(int *numarr)
{

}

int main()
{
	#defube
	int	num_arr[len] = {1, 2, 3, 4, 5};

	
	int num_arr[1] = {1};

	int	i = 0;
	while (num_arr[i])
	{
		int j = i + 1;
		while (num_arr[j])
		{
			if (num_arr[i] == num_arr[j])
			{
				printf("error");
				return(1);
			}
			j++;
		}
		i++;
		if (num_arr[i + 1] == '\0')
			break ;
	}
	return (0);
}