/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 17:11:48 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/15 14:38:30 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_id(int id_num)
{
	char	*str;
	int		len;

	str = ft_itoa(id_num);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
// #include <stdio.h>
// int main()
// {
// 	unsigned int id_num = 0;
// 	int len_ft_id = ft_print_id(id_num);
// 	printf("\t");
// 	int len_id = printf("%d", id_num);
// 	printf("\n%d %d", len_ft_id, len_id);
// }