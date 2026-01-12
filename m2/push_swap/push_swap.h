/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:25:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/12 23:12:49 by sohuikim         ###   ########.fr       */
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

typedef enum s_stack_op_cmd
{
	SWAP_A,
	SWAP_B,
	SWAP_AB,
	PUSH_A,
	PUSH_B,
	ROTATE_A,
	ROTATE_B,
	ROTATE_AB,
	REVERSE_ROTATE_A,
	REVERSE_ROTATE_B,
	REVERSE_ROTATE_AB
}	t_stack_op_cmd;

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

int		is_sign(char c);
int		is_num(char c);
int		is_zero(char c);
long	ft_atol(char *splitstr);
int		handling_input_data(char **argv, t_mem_res *var);
void	check_invalid_num(t_mem_res *var);
void	check_invalid_int_len(t_mem_res *var);
void	check_invalid_int_boundary(t_mem_res *var);
int		cnt_input_data(char **argv);
void	free_split(char **splitstr_arr);
void	free_num_arr(long *num_arr);
void	free_resource(t_error_case error, t_stack *stacks, t_mem_res *var);
void	print_error(void);
void	handle_error_case(t_error_case error, t_mem_res *var);
void	check_duplicate_num(t_mem_res *var);
void	swap_stack(t_list_node *stack);
void	add_node_back(t_list_node *stack);
void	rotate_node(t_list_node *stack);
void	rrotate_node(t_list_node *stack);
void	push_node(t_list_node *stack1, t_list_node *stack2);
void	swap_ops(t_stack_op_cmd cmd, t_stack *stacks);
void	push_ops(t_stack_op_cmd cmd, t_stack *stacks);
void	rotate_ops(t_stack_op_cmd cmd, t_stack *stacks);
void	rrotate_ops(t_stack_op_cmd cmd, t_stack *stacks);
int		find_max_value(t_list_node *stack);
int		max_bit_len(long num);
int	run_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils);
void	sort(t_stack *stacks, int stack_size);
void	insert_sort(t_stack *stacks, t_sort_utils *sort_utils);
void	insert_sort_controller(t_stack *stacks, t_sort_utils *sort_utils);
int	indexing_stack_data(t_mem_res *var);
int	run_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils);
void	binary_radix_sort(t_stack *stacks, t_mem_res *var, t_sort_utils *sort_utils);
void	free_index_arr(int *index_arr);
int	find_stack_data_rank(t_node *cur_node, t_mem_res *var);
#endif