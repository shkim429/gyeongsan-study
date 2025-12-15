/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/13 22:30:34 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		ft_atoi(const char *nptr);
char	*handling_input_data(char *argv);
char	*check_input_error(char **splitstr_arr);

int	main(int argc, char **argv)
{
	int		i;
	char	*reasult;

	if (argc <= 1)
		printf("%s", "input error");
	else
	{
		i = 1;
		while (argv[i])
		{
			reasult = handling_input_data(argv[i]);
			i++;
		}
		// creat_stack_a(&num_arr);
	}
}

char	*handling_input_data(char *argv)
{
	char	**splitstr_arr;
	int		j;

	j = 0;
	splitstr_arr = ft_split(argv, ' ');
	while (splitstr_arr[j])
	{
		check_input_error(&splitstr_arr[j]);
		j++;
	}
}

char	*check_input_error(char **splitstr_arr)
{
	int	k;
	int	l;

	k = 0;
	while (splitstr_arr[k])
	{
		l = 0;
		if (splitstr_arr[k][l] == '+' || splitstr_arr[k][l] == '-')
			l++;
		while (splitstr_arr[k][l] >= '0' && splitstr_arr[k][l] <= '9')
		{
			if (splitstr_arr[k][l + 1] == '\0')
			{
				printf("%s\n", splitstr_arr[k]);
				return (splitstr_arr[k]);
			}
			l++;
		}
		k++;
	}
	printf("%s\n", "input_error");
	return ("error1");
}



// void	creat_stack_a(void *data)
// {
// 	int	node_cnt;

// 	node_cnt = ft_strlen(data);
// 	printf("%d\n", node_cnt);

// }


// int	ft_atoi(const char *nptr)
// {
// 	int	num;
// 	int	sign;
// 	int	i;

// 	num = 0;
// 	sign = 1;
// 	i = 0;

// 	if (nptr[i] == '+')
// 		i++;
// 	if (nptr[i] == '-')
// 	{
// 		sign = -1;
// 		i++;
// 	}
// 	while (nptr[i])
// 	{
// 		if (!(nptr[i] >= '0' && nptr[i] <= '9'))
// 			return (-1);
// 		num = num * 10 + (nptr[i] - '0');
// 		i++;
// 	}
// 	return (num * sign);

// }
// void	init(t_stack *s)
// {
// 	s->head = NULL;
// 	s->size = 0;
// }

// void push(t_stack *s)
// {

// }
