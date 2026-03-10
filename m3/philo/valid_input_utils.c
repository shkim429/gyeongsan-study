/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:07:12 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/10 16:52:09 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_input.h"

bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	else
		return (false);
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	is_zero(char c)
{
	if (c == '0')
		return (true);
	return (false);
}
