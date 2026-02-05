/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:41 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/05 23:07:20 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <sys/types.h>

# define NOT_FOUND -1
# define FAILURE 0
# define SUCCESS 1

typedef struct s_dirs_path // 구조체명 변경 필요
{
	char	**dirs_path;
	char	***cmd_list;
}	t_dirs_path;

typedef struct s_input_var
{
	int		cnt_cmds;
}	t_input_var;

typedef struct s_fd
{
	int		pd[2];
	int		infile_fd;
	int		input_fd;
	int		outfile_fd;
	pid_t	*child_pid;
}	t_fd;

#endif