/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:25:19 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/06 04:28:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef enum s_error_case
{
	ERROR_NUM,
	ERROR_INT_LEN,
	ERROR_INT_BOUNDARY,
	ERROR_DUPLICATE_NUM,
	ERROR_NONE
}	t_error_case;

typedef struct s_malloc_resource
{
	char	**splitstr_arr;
	long	*num_arr;
	int		cnt_input;
}	t_malloc_resource;

int		is_sign(char c);
int		is_num(char c);
int		is_zero(char c);
long	ft_atol(char *splitstr);
long	*handling_input_data(char **argv);
void	check_invalid_num(t_malloc_resource *var);
void	check_invalid_int_len(t_malloc_resource *var);
void	check_invalid_int_boundary(t_malloc_resource *var);
int		cnt_input_data(char **argv);
void	free_split(char **splitstr_arr);
void	free_num_arr(long *num_arr);
void	print_error(void);
void	handle_error_case(t_error_case error, t_malloc_resource *var);
void	check_duplicate_num(t_malloc_resource *var);
void	swap_stack(t_list_node *stack);
void	add_node_back(t_list_node *stack);
void	rotate_node(t_list_node *stack);
void	rrotate_node(t_list_node *stack);

#endif