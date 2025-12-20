/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/20 22:18:26 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int		ft_atoi(const char *nptr);
char	*handling_input_data(char **argv);
char	**check_input_error(char **splitstr_arr);

int	main(int argc, char **argv)
{
	int		i;
	char	**result;
	t_stack	a_stack;
	t_stack	b_stack;

	if (argc <= 1)
		print_error();
	else
	{
		ft_bzero(&a_stack, sizeof(a_stack));
		ft_bzero(&b_stack, sizeof(b_stack));
		result = handling_input_data(argv);

		// handling_input_data(&argv);
		// while (argv[i])
		// {
		// 	reasult = handling_input_data(argv[i]);
		// 	if (reasult == "error1")
		// 	{
		// 		printf("%s\n", "input error");
		// 		return (-1);
		// 	}
		// 	i++;
		// }
		// creat_stack_a(&num_arr);
	}
}

// char	*handling_input_data(char **argv) // 에러 판단(정상 입력이면 atoi 변환하여 넘기기, 비정상 입력이면 error 넘기고, 즉시 중단)
// {
// 	char	**splitstr_arr;
// 	char	**check_input_arr;
// 	int		i;
// 	int		j;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		splitstr_arr = ft_split(argv[i], ' ');
// 		check_input_arr = check_input_error(splitstr_arr);
// 		while (check_input_arr[j])
// 		{
// 			if (check_input_arr[j] == "error")
// 			{
// 				print_error();
// 				return ;
// 			}
// 			// write(1, check_input_arr[j], ft_strlen(check_input_arr[j])); //임시 출력용
// 			// write(1, "\n", 1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	if(!argv[i])
// 	{
// 		i = 1;
// 		while (argv[i])
// 		{
// 			j = 0;
// 			while (check_input_arr[j])
// 			{
// 				write(1, check_input_arr[j], ft_strlen(check_input_arr[j])); //임시 출력용
// 				write(1, "\n", 1);
// 				j++;
// 			}
// 			i++;
// 		}
// 	}
// }

char	*handling_input_data(char **argv) // 에러 판단(정상 입력이면 atoi 변환하여 넘기기, 비정상 입력이면 error 넘기고, 즉시 중단)
{
	char	**splitstr_arr;
	char	**check_input_arr;
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		splitstr_arr = ft_split(argv[i], ' ');
		check_input_arr[k] = check_input_error(splitstr_arr);
		while (check_input_arr[j])
		{
			if (check_input_arr[j] == "error")
			{
				print_error();
				return ;
			}
			// write(1, check_input_arr[j], ft_strlen(check_input_arr[j])); //임시 출력용
			// write(1, "\n", 1);
			j++;
		}
		i++;
	}
	if(!argv[i])
	{
		i = 1;
		while (argv[i])
		{
			j = 0;
			while (check_input_arr[j])
			{
				write(1, check_input_arr[j], ft_strlen(check_input_arr[j])); //임시 출력용
				write(1, "\n", 1);
				j++;
			}
			i++;
		}
	}
}

char	**check_input_error(char **splitstr_arr) // 입력값 형태 확인(숫자인지)
{
	char	*str_arr;
	int		k;
	int		l;

	k = 0;
	while (splitstr_arr[k])
	{
		l = 0;
		if (splitstr_arr[k][l] == '+' || splitstr_arr[k][l] == '-')
			l++;
		while (splitstr_arr[k][l] >= '0' && splitstr_arr[k][l] <= '9')
		{
			if (splitstr_arr[k][l + 1] == '\0')
				break ;
			l++;
		}
		if ((splitstr_arr[k][l] == '+' || splitstr_arr[k][l] == '-') || \
		((!(splitstr_arr[k][l] >= '0' && splitstr_arr[k][l] <= '9'))) || \
			splitstr_arr[k][l + 1] != '\0')
			splitstr_arr[k] = "error";
		if (splitstr_arr[k][l + 1] == '\0' && splitstr_arr[k + 1] == NULL)
			break ;
		k++;
	}
	return (splitstr_arr);
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
