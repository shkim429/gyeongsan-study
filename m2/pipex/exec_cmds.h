/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:55:15 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/12 16:53:19 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_CMDS_H
# define EXEC_CMDS_H

# include "pipex.h"

bool	run_cmd(char **envp, char **argv, t_pipe_util *pipe_util);
bool	exec_cmd(char **envp, char **argv, t_pipe_util *pipe_util, int i);
bool	exec_last_cmd(char **envp, char **argv, t_pipe_util *pipe_util, int i);
void	exec_child_p(char **envp, char **argv, t_pipe_util *pipe_util, int i);
bool	prepare_io(t_pipe_util *pipe_util, int i);

#endif