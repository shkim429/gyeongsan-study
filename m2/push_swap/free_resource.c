/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:17:06 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/12 15:24:52 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_split(char **splitstr_arr)
{
	int	i;

	i = 0;
	while (splitstr_arr[i])
	{
		free(splitstr_arr[i]);
		i++;
	}
	free(splitstr_arr);
	splitstr_arr = NULL;
}

void	free_num_arr(long *num_arr)
{
	free(num_arr);
	num_arr = NULL;
}

void	free_index_arr(int *index_arr)
{
	free(index_arr);
	index_arr = NULL;
}