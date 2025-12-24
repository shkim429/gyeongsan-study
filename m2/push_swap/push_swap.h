/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:25:19 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/24 21:31:04 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*head;
	t_node	*tail;
}	t_stack;

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
	int		**num_arr;
}	t_malloc_resource;

void	creat_stack_a(void *data);
int		is_valid_num(char *input_str);
void	print_error(void);
void	free_split(char **splitstr_arr);
#endif