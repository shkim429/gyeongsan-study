/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list_util.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:04:43 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/11 15:05:43 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_CMD_LIST_UTIL_H
# define GET_CMD_LIST_UTIL_H

# include "pipex.h"

int	split_path_dirs(char **envp, t_pipe_util *util);
int	get_cmd_list(int argc, char	**argv, t_pipe_util *util);
int	cnt_input_cmds(int argc);
int	get_idx_chr(char *str, char c);

#endif