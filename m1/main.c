/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:34 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/31 17:13:28 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int main()
{
	// int d = 456;
	// char d = 'a';
	char *d = "abc";
	int len = ft_printf("123%s\n", d);
	int len2 = printf("123%s\n", d);
	printf("%d %d", len, len2);
}