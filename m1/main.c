/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:34 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/12 23:28:31 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int main()
{
	// int d = 456;
	// char d = 'a';
	// char *str_d = "13";
	unsigned int num_d = 132;
	int len = ft_printf("%x\n", num_d);
	int len2 = printf("%x\n", num_d);
	printf("%d %d", len, len2);
}