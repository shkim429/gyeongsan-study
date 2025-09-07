/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:24:34 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/07 20:07:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
int main()
{
	 int id = INT_MIN;
	char c = '\0';
	char *s = 0;
	unsigned int uxX = 42;
	unsigned int *p = NULL;
	printf("==id 출력 결과==\n");
	int len_ft_id = ft_printf("%q %d", id, id);
	printf("\t");
	int len_id = printf("%q %d", id, id);
	printf("\n");
	printf("(길이: %d %d)\n", len_ft_id, len_id);
	printf("==c 출력 결과==\n");
	int len_ft_c = ft_printf("%c\t", c);
	int len_c = printf("%c\t", c);
	printf("(길이: %d %d)\n", len_ft_c, len_c);
	printf("==s 출력 결과==\n");
	int len_ft_s = ft_printf("%s\t", s);
	int len_s = printf("%s\t", s);
	printf("(길이: %d %d)\n", len_ft_s, len_s);
	printf("==u 출력 결과==\n");
	int len_ft_u = ft_printf("%u\t", uxX);
	int len_u = printf("%u\t", uxX);
	printf("(길이: %d %d)\n", len_ft_u, len_u);
	printf("==x 출력 결과==\n");
	int len_ft_x = ft_printf("%x\t", uxX);
	int len_x = printf("%x\t", uxX);
	printf("(길이: %d %d)\n", len_ft_x, len_x);
	printf("==X 출력 결과==\n");
	int len_ft_X = ft_printf("%X\t", uxX);
	int len_X = printf("%X\t", uxX);
	printf("(길이: %d %d)\n", len_ft_X, len_X);
	printf("==p 출력 결과==\n");
	int len_ft_p = ft_printf("%p\t", p);
	int len_p= printf("%p\t", p);
	printf("(길이: %d %d)\n", len_ft_p, len_p);
}
