/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:34 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/02 02:51:12 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int main()
{
	// int d = 456;
	// char d = 'a';
	// char *d = "abc";
	unsigned int d = -1;
	int len = ft_printf("abc%u\n", d);
	int len2 = printf("abc%u\n", d);
	printf("%d %d", len, len2);
}