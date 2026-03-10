/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_func_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 02:57:54 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/10 14:20:07 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general_func_utils.h"
#include <string.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	total_size;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	s = (void *)malloc(total_size);
	if (s == NULL)
		return (NULL);
	memset(s, 0, total_size);
	return (s);
}
