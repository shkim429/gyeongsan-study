/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 01:47:41 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 00:17:18 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdbool.h>
# include <sys/types.h>

typedef struct s_cmd_path
{
	char	**dirs_path;
	char	***cmd_list;
	int		cnt_cmds;
}	t_cmd_path;

typedef struct s_fd
{
	int		pd[2];
	int		input_fd;
	int		outfile_fd;
	pid_t	*child_pid;
}	t_fd;

typedef struct s_pipe_util
{
	t_cmd_path	*cmd_path;
	t_fd		*fd;
	int			child_status;
}	t_pipe_util;

void	init_all_struct(t_pipe_util *pipe_util, t_cmd_path *cmd_path, t_fd *fd);
void	bind_struct(t_pipe_util *pipe_util, t_cmd_path *cmd_path, t_fd *fd);

#endif