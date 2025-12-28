/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/28 23:09:18 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

long	ft_atol(char *splitstr);
long	*handling_input_data(char **argv);
void	check_invalid_num(t_malloc_resource *var);
void	check_invalid_int_len(t_malloc_resource *var);
void	check_invalid_int_boundary(t_malloc_resource *var);
int		cnt_input_data(char **argv);
void	check_duplicate_num(t_malloc_resource *var);
int		is_sign(char c);
int		is_num(char c);
int		is_zero(char c);

int	main(int argc, char **argv)
{
	int		i;
	long	*num_arr;
	// t_stack	a_stack;
	// t_stack	b_stack;

	if (argc <= 1)
		print_error();
	else
	{
		i = 0;
		// ft_bzero(&a_stack, sizeof(a_stack));
		// ft_bzero(&b_stack, sizeof(b_stack));
		num_arr = handling_input_data(argv);
		printf("%ld\n", num_arr[0]);
		printf("%ld\n", num_arr[1]);
		printf("%ld\n", num_arr[2]);
		// printf("%d\n", num_arr[1]);
		// printf("%d\n", num_arr[2]);

		// while (num_arr[i])
		// {
		// 	write(1, result[i], ft_strlen(result[i])); //임시 출력용
 		// 	write(1, "\n", 1);
		// 	i++;
		// }
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
long	*handling_input_data(char **argv)
{
	t_malloc_resource	var;
	int					i;
	int					j;
	int					k;

	var.cnt_input = cnt_input_data(argv);
	var.num_arr = ft_calloc(((var.cnt_input) + 1), sizeof(*(var.num_arr)));
	i = 1;
	k = 0;
	while (argv[i])
	{
		var.splitstr_arr = ft_split(argv[i], ' ');
		check_invalid_num(&var);
		check_invalid_int_len(&var);
		j = 0;
		while (var.splitstr_arr[j])
		{
			var.num_arr[k++] = ft_atol(var.splitstr_arr[j++]);
			check_invalid_int_boundary(&var);
		}
		i++;
	}
	check_duplicate_num(&var);
	return (var.num_arr);
}

/* int 범위 오버/언더 여부 확인(10) */
void	check_invalid_int_len(t_malloc_resource *var)
{
	int	i;
	int	j;
	int	num_len;

	i = 0;
	num_len = 0;
	while (var->splitstr_arr[i])
	{
		j = 0;
		if (is_sign(var->splitstr_arr[i][j]))
			j++;
		while (is_zero(var->splitstr_arr[i][j]))
			j++;
		while (is_num(var->splitstr_arr[i][j]))
		{
			num_len++;
			if (num_len > 10)
				return (handle_error_case(ERROR_INT_LEN, var));
			j++;
		}
		i++;
	}
	return ;
}

/* 입력값 = 숫자 확인 */
void	check_invalid_num(t_malloc_resource *var)
{
	int	i;
	int	j;

	i = 0;
	while (var->splitstr_arr[i])
	{
		j = 0;
		if (is_sign(var->splitstr_arr[i][j]))
			j++;
		while (is_num(var->splitstr_arr[i][j]))
		{
			if (var->splitstr_arr[i][j + 1] == '\0')
				break ;
			j++;
		}
		if ((is_sign(var->splitstr_arr[i][j])) || \
		(!(is_num(var->splitstr_arr[i][j]))))
			return (handle_error_case(ERROR_NUM, var));
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

	num = 0;
	sign = 1;
	i = 0;
	if (splitstr[i] == '+')
		i++;
	else if (splitstr[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (splitstr[i])
	{
		num = num * 10 + (splitstr[i] - '0');
		i++;
	}
	return (num * sign);
}

/* int 범위 경계값(길이: 10) 오버/언더 확인 */
void	check_invalid_int_boundary(t_malloc_resource *var)
{
	int	i;

	i = 0;
	if (var->num_arr[i] < 0)
	{
		if (var->num_arr[i] < -2147483648)
			return (handle_error_case(ERROR_INT_BOUNDARY, var));
	}
	else
	{
		if (var->num_arr[i] > 2147483647)
			return (handle_error_case(ERROR_INT_BOUNDARY, var));
	}
}

/* 입력 숫자 중복 확인 */
void	check_duplicate_num(t_malloc_resource *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < var->cnt_input)
	{
		j = i + 1;
		while (j < var->cnt_input)
		{
			if (var->num_arr[i] == var->num_arr[j])
				return (handle_error_case(ERROR_DUPLICATE_NUM, var));
			j++;
		}
		i++;
	}
}
/* 입력값 길이 검사: 0 건너뛰기*/
int	is_zero(char c)
{
	if (c == '0')
		return (1);
	return (0);
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