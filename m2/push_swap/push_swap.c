/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/06 04:27:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

long	ft_atol(char *splitstr);
long	*handling_input_data(char **argv);
int		cnt_input_data(char **argv);
void	init_stack(t_list_node *stack);
t_node	*create_new_node(long num);
void	create_stack(t_list_node *stack, long *num_arr, int node_cnt);

int	main(int argc, char **argv)
{
	int			i;
	long		*num_arr;
	t_list_node	stack_a;
	t_list_node	stack_b;
	t_malloc_resource var;

	if (argc <= 1)
		print_error();
	else
	{
		var.cnt_input = cnt_input_data(argv);
		num_arr = handling_input_data(argv);
		init_stack(&stack_a);
		init_stack(&stack_b);
		create_stack(&stack_a, num_arr, var.cnt_input);
		// swap_stack(&stack_a);
		// rotate_node(&stack_a);
		rrotate_node(&stack_a);
		printf("%ld\n", num_arr[0]);
		printf("%ld\n", num_arr[1]);
	}
}

/* 스택 초기화 */
void	init_stack(t_list_node *stack)
{
	ft_bzero(stack, sizeof(stack));
}

/* 스택 생성 */
void	create_stack(t_list_node *stack, long *num_arr, int node_cnt)
{
	stack->head = create_new_node(num_arr[stack->size]);
	stack->tail = stack->head;
	while (++(stack->size) < node_cnt)
	{
		stack->tail->next = create_new_node(num_arr[stack->size]);
		stack->tail = stack->tail->next;
	}
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