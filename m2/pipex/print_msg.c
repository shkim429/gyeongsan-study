/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 03:13:57 by sohuikim          #+#    #+#             */
/*   Updated: 2026/03/05 17:40:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "ft_libft.h"
#include <errno.h>
#include "libft.h"
#include <stdio.h>

void	print_cur_exe_name(char **argv)
{
	write(2, argv[0], ft_strlen(argv[0]));
	write(2, ": ", 2);
}

void	print_errno(char **argv, char *error_obj)
{
	print_cur_exe_name(argv);
	perror(error_obj);
}

void	print_error_msg(char **argv, char *error_obj)
{
	print_cur_exe_name(argv);
	write(2, error_obj, ft_strlen(error_obj));
	write(2, ": ", 2);
	write(2, "command not found", ft_strlen("command not found"));
	write(2, "\n", 2);
}
