/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 02:21:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "error.h"
#include "input_valid.h"
#include "create_stack.h"
#include "sort.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack				stacks;
	t_mem_res			var;
	int					i;

	if (argc <= 1)
		print_error();
	else
	{
		init_all_struct(&var, &stacks);
		if ((run_push_swap(argv, &var, &stacks)) == FAILURE)
			return (free_res(ERROR_MALLOC, &stacks, &var), FAILURE);
		else
			return (free_res(ERROR_NONE, &stacks, &var), SUCCESS);
	}
}

int	run_push_swap(char **argv, t_mem_res *var, t_stack *stacks)
{
	t_sort_utils		sort_utils;

	ft_bzero(&sort_utils, sizeof(t_sort_utils));
	var->cnt_input = cnt_input_data(argv);
	if (!var->cnt_input)
		return (FAILURE); // ft_split 실패
	if (!handle_input_data(argv, var)) // num_arr 실패 or split 실패
		return (FAILURE);
	if (!check_vaild_sort_state(var)) // split과 num free 필요
		return (FAILURE);
	if (!create_stack_a(&(stacks->a), var))
		return (FAILURE);
	else
	{
		if (!run_sort(stacks, var, &sort_utils))
			return (FAILURE);
		return (SUCCESS);
	}
}

/* 구조체 초기화 */
void	init_all_struct(t_mem_res *var, t_stack *stack)
{
	ft_bzero(var, sizeof(t_mem_res));
	ft_bzero(stack, sizeof(t_stack)); // sizeof(*stack) 다시 확인하기
}

/* 입력값 배열 저장을 위한 입력 요소 길이 카운트 */
int	cnt_input_data(char **argv)
{
	char	**split_input_arr;
	int		cnt_input;
	int		i;
	int		j;

	i = 1;
	cnt_input = 0;
	while (argv[i])
	{
		j = 0;
		split_input_arr = ft_split(argv[i], ' ');
		if (split_input_arr == NULL)
			return (FAILURE);
		while (split_input_arr[j])
		{
			cnt_input++;
			j++;
		}
		free_split(split_input_arr);
		i++;
	}
	return (cnt_input);
}
/* 에러 판단(정상 입력이면 atoi 변환하여 넘기기, 비정상 입력이면 error 넘기고, 즉시 중단) */
int	handle_input_data(char **argv, t_mem_res *var)
{
	int		i;
	int		j;
	int		k;

	var->num_arr = ft_calloc(((var->cnt_input) + 1), sizeof(*(var->num_arr)));
	if (var->num_arr == NULL)
		return (FAILURE);
	i = 1;
	k = 0;
	while (argv[i])
	{
		if (var->splitstr_arr != NULL)
			free_split(var->splitstr_arr);
		var->splitstr_arr = ft_split(argv[i], ' ');
		if (!var->splitstr_arr)
			return (FAILURE);
		check_invalid_num(var);
		check_invalid_int_len(var);
		j = 0;
		while (var->splitstr_arr[j])
		{
			var->num_arr[k++] = ft_atol(var->splitstr_arr[j++]);
			check_invalid_int_boundary(var);
		}
		i++;
	}
	check_duplicate_num(var);
	return (SUCCESS);
}
