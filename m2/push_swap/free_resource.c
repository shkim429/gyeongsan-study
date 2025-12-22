/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resource.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:17:06 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/21 21:05:45 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}
