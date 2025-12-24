/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/24 21:48:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long	ft_atol(char *splitstr);
int		**ft_atol_arr(char **argv, char **splitstr_arr);
int		handling_input_data(char **argv);
void	check_invalid_num(char **splitstr);
void	check_invalid_int_len(char **splitstr);
void	check_invalid_int_boundary(long num);
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
int	handling_input_data(char **argv)
{
	char	**splitstr_arr;
	int		**num_arr;
	int		i;
	int		j;
	int		k;

	// num_arr = (int **)ft_calloc((cnt_input_data(argv) + 1), sizeof(int));
	i = 1;
	k = 0;
	while (argv[i])
	{
		splitstr_arr = ft_split(argv[i], ' ');
		check_invalid_num(splitstr_arr);
		check_invalid_int_len(splitstr_arr);
		j = 0;
		while (splitstr_arr[j])
		{
			num_arr[k] = ft_atol(splitstr_arr[j]);
			check_invalid_int_boundary(num_arr[k]);
			check_duplicate_num(num_arr[k]);
		}
		i++;
	}
	return (num_arr);
}


/* int 범위 오버/언더 여부 확인(10) */
void	check_invalid_int_len(char **splitstr_arr)
{
	int	i;
	int	j;
	int	num_len;

	i = 0;
	num_len = 0;
	while (splitstr_arr[i])
	{
		j = 0;
		if (is_sign(splitstr_arr[i][j]))
			j++;
		while (is_num(splitstr_arr[i][j]))
		{
			num_len++;
			if (num_len > 10)
				return (handle_error_case(ERROR_INT_LEN, splitstr_arr));
			j++;
		}
		i++;
	}
	return ;
}

/* 입력값 = 숫자 확인 */
void	check_invalid_num(char **splitstr_arr)
{
	int	i;
	int	j;

	i = 0;
	while (splitstr_arr[i])
	{
		j = 0;
		if (is_sign(splitstr_arr[i][j]))
			j++;
		while (is_num(splitstr_arr[i][j]))
		{
			if (splitstr_arr[j + 1] == '\0')
				break ;
			j++;
		}
		if ((is_sign(splitstr_arr[i][j])) || (!(is_num(splitstr_arr[i][j]))))
			return (handle_error_case(ERROR_NUM), splitstr_arr);
		i++;
	}
	return ;
}


/* 보류
int	**ft_atol_arr(char **argv, char **splitstr_arr)
{
	while (argv[i])
}
*/

/* 입력 문자열 -> 숫자 변환 */
long	ft_atol(char *splitstr)
{
	int64_t	num;
	int		sign;
	int		i;
	int		j;

	num = 0;
	sign = 1;
	i = 0;
	while (splitstr[i])
	{
		num = 0;
		if (splitstr[i] == '+')
			i++;
		if (splitstr[i] == '-')
		{
			sign = -1;
			i++;
		}
		num = num * 10 + (splitstr[i] - '0');
		i++;
	}
	return (num * sign);
}

/* int 범위 경계값(길이: 10) 오버/언더 확인 */
void	check_invalid_int_boundary(long num)
{
	if (num < 0)
	{
		if (num < -2147483648)
			return (handling_input_data(ERROR_INT_BOUNDARY));
	}
	else
	{
		if (num > 2147483647)
			print_error();
			return ;
	}
}

/* 입력 숫자 중복 확인 */
void	check_duplicate_num(int **num_arr)
{

}

/* 입력값 형태: 부호 확인 */
int	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);

}

/* 입력값 형태: 숫자 확인 */
int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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


// void	creat_stack_a(void *data)
// {
// 	int	node_cnt;

// 	node_cnt = ft_strlen(data);
// 	printf("%d\n", node_cnt);

// }