/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:46:43 by sohuikim          #+#    #+#             */
/*   Updated: 2025/06/30 13:53:48 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*memmove(void *dest, const void *src, size_t n)
// {
	
// }

int	main()
{
	char src1[10] = "123";
	char dest1[10] = "456";

	
	char src2[10] = "1234567";
	char dest2[10] = "890";

	char src3[11] = "123456";

	printf("src1 = %s, dest1 = %s\n", src1, dest1);
	printf("src1 = %s, dest1 = %s\n\n", src1, (char *)memcpy(src1+1, src1, 5));
	printf("src2 = %s, dest2 = %s\n", src2, dest2);
	printf("src2 = %s, dest2 = %s\n\n", src2, (char *)memmove(src2+1, src2, 5));
	printf("src3 = %s\n", src3);
	printf("src3 = %s\n\n", (char *)memcpy(src3+1, src3, 2));

	char str[] = "stackoverflow";
printf("str = %s\n", (char *)memcpy(&str[0], &str[1], 4));  // 겹치는 영역에서 문제가 발생할 수 있음

printf("str = %s", (char *)memmove(&str[0], &str[1], 4));  // 안전하게 복사됨

}

// src[6] = 123456
// memcpy(src+1, src, 5)

// src[0] = 1  src[1] = 2
// src[1] = 2  src[2] = 3
// src[2] = 3  src[3] = 4
// src[3] = 4  src[4] = 5
// src[4] = 5  src[5] = 6
// src[5] = 6

// src[1] = src[0] = 1 //11
// src[2] = src[1] = 1 //111
// src[3] = src[2] = 1 //1111
// src[4] = src[3] = 1 //11111
// src[5] = src[6] = 1 //111111


// src[5] = src[4]