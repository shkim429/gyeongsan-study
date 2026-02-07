/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 00:09:20 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/07 16:21:19 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_libft.h"

void	print_error(char *error_title, char *error_msg)
{
	write(STDERR_FILENO, "error\n", 6);
	write(STDERR_FILENO, error_title, ft_strlen(error_title));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, error_msg, ft_strlen(error_msg));
	write(STDERR_FILENO, "\n", 2);
}
