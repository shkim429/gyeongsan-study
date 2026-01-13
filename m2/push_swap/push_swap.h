/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:25:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/13 17:47:59 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SUCCESS 1
# define FAILURE 0

typedef struct s_node
{
	long			data;
	struct s_node	*next;
}	t_node;

typedef struct s_list_node
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_list_node;

typedef struct s_stack
{
	t_list_node	a;
	t_list_node	b;
}	t_stack;

typedef enum s_error_case
{
	ERROR_NUM,
	ERROR_INT_LEN,
	ERROR_INT_BOUNDARY,
	ERROR_DUPLICATE_NUM,
	ERROR_MALLOC,
	ERROR_NONE,
}	t_error_case;

typedef struct s_mem_res
{
	char	**splitstr_arr;
	long	*num_arr;
	int		*index_arr;
	int		cnt_input;
}	t_mem_res;

typedef struct s_sort_utils
{
	t_node	*key;
	int		max_value;
	int		min_value;
}	t_sort_utils;

int		cnt_input_data(char **argv);
int		handle_input_data(char **argv, t_mem_res *var);
void	init_all_struct(t_mem_res *var, t_stack *stack);
int		run_push_swap(char **argv, t_mem_res *var, t_stack *stack);
int		run_sort(t_stack *stack, t_mem_res *var, t_sort_utils *sort_utils);
void	insert_sort(t_stack *stack, t_sort_utils *sort_utils);
void	run_insert_sort(t_stack *stack, t_sort_utils *sort_utils, int a_size);
void	radix_sort(t_stack *stack, t_mem_res *var, t_sort_utils *sort_utils);

#endif