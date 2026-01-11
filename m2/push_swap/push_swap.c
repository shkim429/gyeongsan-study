/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/11 06:21:17 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

long	ft_atol(char *splitstr);
int		handling_input_data(char **argv, t_malloc_resource *var);
int		cnt_input_data(char **argv);
void	init_all_stack(t_malloc_resource *var, t_stack *stack);
t_node	*create_new_node(long num);
int		create_stack_a(t_list_node *stack_a, t_malloc_resource *var);
int		check_vaild_sort_state(t_malloc_resource *var);
int		run_push_swap(char **argv, t_malloc_resource *var, t_stack *stacks);

int	main(int argc, char **argv)
{
	t_stack				stacks;
	t_malloc_resource	var;
	int					i;

	if (argc <= 1)
		print_error();
	else
	{
		init_all_stack(&var, &stacks);
		if ((run_push_swap(argv, &var, &stacks)) == FAILURE)
		{
			printf("%d", 1);
			return (free_resource(ERROR_MALLOC, &stacks, &var), FAILURE);
		}
		else
		{
			printf("%d", 0);
			return (free_resource(ERROR_NONE, &stacks, &var), FAILURE);
		}
	}
}

int	run_push_swap(char **argv, t_malloc_resource *var, t_stack *stacks)
{
	var->cnt_input = cnt_input_data(argv);
	if (!var->cnt_input)
		return (FAILURE); // ft_split 실패
	if (!handling_input_data(argv, var)) // num_arr 실패 or split 실패
		return (FAILURE);
	if (!check_vaild_sort_state(var)) // split과 num free 필요
		return (FAILURE);
	printf("%d", 2);
	if (!create_stack_a(&(stacks->a), var))
		return (FAILURE);
	else
	{
		sort(stacks, var->cnt_input);
		return (SUCCESS);
	}
}

/* 스택 초기화 */
void	init_all_stack(t_malloc_resource *var, t_stack *stack)
{
	ft_bzero(var, sizeof(t_malloc_resource));
	ft_bzero(stack, sizeof(t_stack)); // sizeof(*stack) 다시 확인하기
}

/* 스택 생성 */
int	create_stack_a(t_list_node *stack_a, t_malloc_resource *var)
{
	stack_a->head = create_new_node(var->num_arr[stack_a->size]);
	if (stack_a->head == NULL)
		return (FAILURE);
	stack_a->tail = stack_a->head;
	while (++(stack_a->size) < var->cnt_input)
	{
		stack_a->tail->next = create_new_node(var->num_arr[stack_a->size]);
		if (stack_a->tail->next == NULL)
			return (FAILURE);
		stack_a->tail = stack_a->tail->next;
	}
	return (1);
}

/* 노드 생성 */
t_node	*create_new_node(long num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = num;
	new_node->next = NULL;
	return (new_node);
}

/* 노드 연결 */
t_node	*addnode_back(t_node **cur_lst, t_node *new_node)
{
	if (*cur_lst == NULL)
		*cur_lst = new_node;
	else
		(*cur_lst)->next = new_node;
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
int	handling_input_data(char **argv, t_malloc_resource *var)
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
		var->splitstr_arr = ft_split(argv[i], ' ');
		if (var->splitstr_arr == NULL)
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

int	check_vaild_sort_state(t_malloc_resource *var)
{
	int	i;
	int	j;

	i = 0;
	while (i < (var->cnt_input) - 1)
	{
		if (var->num_arr[i] > var->num_arr[i + 1])
			return (SUCCESS); // error
		i++;
	}
	return (FAILURE);
}
