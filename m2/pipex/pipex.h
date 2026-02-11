/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:41 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/11 20:44:06 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>

# define NOT_FOUND -1
# define FAILURE 0
# define SUCCESS 1

typedef struct s_pipe_util
{
	char	**dirs_path;
	// t_cmd	*head;
	// int		cmd_size;
	char	***cmd_list;
	int		cnt_cmds;
}	t_pipe_util;

typedef struct s_fd
{
	int		pd[2];
	int		infile_fd;
	int		input_fd;
	int		outfile_fd;
	pid_t	*child_pid;
}	t_fd;

#endif
// "ls -l" 
// typedef struct s_cmd
// {
// 	char			**cmd;
//	int				pipe[2];
// 	struct s_cmd	*next;
// 	struct s_cmd	*prev;
// }	t_cmd;

// typedef struct s_list
// {
// 	t_cmd	*head;
// 	t_cmd	*tail;
// 	int		size;
// 	char	*in_file;
// 	char	*out_file;
// 	int		in_fd;
// 	int		out_fd;
// }	t_list;


// prev
// dupread
// close()
// close()

// dup (read);
// close()
// close()

