/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 13:37:51 by sohuikim          #+#    #+#             */
/*   Updated: 2025/12/21 19:20:32 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_num(char *input_str)
{
	int	i;

	i = 0;
	if (ft_strncmp(input_str, "error", ft_strlen(input_str)) == 0)
		return (1);
	return (0);
}


