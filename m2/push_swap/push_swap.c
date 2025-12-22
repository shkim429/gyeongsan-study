/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/22 21:18:30 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *nptr);
char	**handling_input_data(char **argv);
char	*flag_invalid_num(char *splitstr_arr);
char	**flag_invalid_int_len(char **str_num);
int		cnt_input_data(char **argv);

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
		i = 0;
		ft_bzero(&a_stack, sizeof(a_stack));
		ft_bzero(&b_stack, sizeof(b_stack));
		result = handling_input_data(argv);
		if (!result)
			return (0);
		while (result[i])
		{
			write(1, result[i], ft_strlen(result[i])); //임시 출력용
 			write(1, "\n", 1);
			i++;
		}
		// return (0);
	}
}

/* 입력값 배열 저장을 위한 입력 요소 길이 카운트 */
int	cnt_input_data(char **argv)
{
	char	**splitstr_arr;
	int		cnt_input;
	int		i;
	int		j;

	i = 1;
	cnt_input = 0;
	while (argv[i])
	{
		j = 0;
		splitstr_arr = ft_split(argv[i], ' ');
		while (splitstr_arr[j])
		{
			cnt_input++;
			j++;
		}
		free_split(splitstr_arr);
		i++;
	}
	return (cnt_input);
}


/* 에러 판단(정상 입력이면 atoi 변환하여 넘기기, 비정상 입력이면 error 넘기고, 즉시 중단) */
char	**handling_input_data(char **argv)
{
	char	**splitstr_arr;
	char	**input_arr;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	input_arr = (char **)ft_calloc((cnt_input_data(argv) + 1), sizeof(char *));
	while (argv[i])
	{
		j = 0;
		splitstr_arr = ft_split(argv[i], ' '); // 입력값 분리(공백)
		while (splitstr_arr[j])
		{
			input_arr[k] = flag_invalid_num(splitstr_arr[j]);
			if (is_valid_num(input_arr[k]))
			{
				print_error();
				return (NULL);
			}
			j++;
			k++;
		}
		i++;
	}
	return(push_swap_atoi(flag_invalid_int_len(input_arr)));
}

/* int 범위 오버/언더 여부 확인(10) */
char	**flag_invalid_int_len(char **str_num)
{
	int	i;
	int	j;
	int	num_len;

	i = 0;
	while (str_num[i]) // 3번 루프
	{
		j = 0;
		num_len = 0;
		if (str_num[i][j] == '+' || str_num[i][j] == '-')
			j++;
		while (str_num[i][j] >= '0' && str_num[i][j] <= '9')
		{
			num_len++;
			if (num_len > 10)
			{
				print_error();
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (str_num);
}

/* 입력값 = 숫자 확인 */
char	*flag_invalid_num(char *splitstr)
{
	char	*str_arr;
	int		l;

	l = 0;
	if (splitstr[l] == '+' || splitstr[l] == '-')
		l++;
	while (splitstr[l] >= '0' && splitstr[l] <= '9')
	{
		if (splitstr[l + 1] == '\0')
			break ;
		l++;
	}
	if ((splitstr[l] == '+' || splitstr[l] == '-') || \
	((!(splitstr[l] >= '0' && splitstr[l] <= '9'))))
		splitstr = "error";
	return (splitstr);
}

// void	creat_stack_a(void *data)
// {
// 	int	node_cnt;

// 	node_cnt = ft_strlen(data);
// 	printf("%d\n", node_cnt);

// }

int	ft_atol (char **nptr)
{
	int64_t	num;
	int		sign;
	int		i;
	int		j;

	num = 0;
	sign = 1;
	i = 0;
	while (nptr[i])
	{
		j = 0;
		if (nptr[i][j] == '+')
 			j++;
 		if (nptr[i][j] == '-')
 		{
 			sign = -1;
 			j++;
 		}
 		while (nptr[i][j])
 		{
 			num = num * 10 + (nptr[i][j] - '0');
 			j++;
 		}
		i++;
	}
	return (num * sign);

}
// }
// void	init(t_stack *s)
// {
// 	s->head = NULL;
// 	s->size = 0;
// }

// void push(t_stack *s)
// {

// }
