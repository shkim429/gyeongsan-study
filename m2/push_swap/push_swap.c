/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:28:32 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/15 04:36:03 by sohuikim         ###   ########.fr       */
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
	t_stack				stack;
	t_mem_res			var;

	if (argc <= 1)
		print_error();
	else
	{
		init_all_struct(&var, &stack);
		if ((run_push_swap(argv, &var, &stack)) == FAILURE)
			return (free_res(ERROR_MALLOC, &stack, &var), FAILURE);
		else
			return (free_res(ERROR_NONE, &stack, &var), SUCCESS);
	}
}

int	run_push_swap(char **argv, t_mem_res *var, t_stack *stack)
{
	t_sort_utils		sort_utils;

	ft_bzero(&sort_utils, sizeof(t_sort_utils));
	var->cnt_input = cnt_input_data(argv);
	if (!var->cnt_input)
		return (FAILURE);
	if (!handle_input_data(argv, var))
		return (FAILURE);
	if (!check_valid_sort_state(var))
		return (FAILURE);
	if (!create_stack_a(&(stack->a), var))
		return (FAILURE);
	else
	{
		if (!run_sort(stack, var, &sort_utils))
			return (FAILURE);
		return (SUCCESS);
	}
}

void	init_all_struct(t_mem_res *var, t_stack *stack)
{
	ft_bzero(var, sizeof(t_mem_res));
	ft_bzero(stack, sizeof(t_stack));
}

int	cnt_input_data(char **argv)
{
	char	**split_input_arr;
	int		cnt_input;
	int		i;
	int		j;

	cnt_input = 0;
	while (argv[++i])
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
	}
	return (cnt_input);
}

int	handle_input_data(char **argv, t_mem_res *var)
{
	static int	i;
	int			j;
	static int	k;

	var->num_arr = ft_calloc(((var->cnt_input)), sizeof(*(var->num_arr)));
	if (var->num_arr == NULL)
		return (FAILURE);
	while (argv[++i])
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
			var->num_arr[k] = ft_atol(var->splitstr_arr[j++]);
			check_invalid_int_boundary(var->num_arr[k++], var);
		}
	}
	check_duplicate_num(var);
	return (SUCCESS);
}
