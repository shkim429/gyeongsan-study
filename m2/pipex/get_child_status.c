/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 02:48:42 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:53:33 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_child_status.h"
#include <stdlib.h>
#include <sys/wait.h>

void	return_child_status(t_pipe_util *pipe_util)
{
	int	child_status_code;

	child_status_code = 0;
	if (WIFEXITED(pipe_util->child_status))
		child_status_code = WEXITSTATUS(pipe_util->child_status);
	else if (WIFSIGNALED(pipe_util->child_status))
		child_status_code = WTERMSIG(pipe_util->child_status);
	else if (WIFSTOPPED(pipe_util->child_status))
		child_status_code = WSTOPSIG(pipe_util->child_status);
	exit (child_status_code);
}
