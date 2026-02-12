/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_path.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:04:43 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:12:37 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_EXEC_PATH_H
# define GET_EXEC_PATH_H

# include "pipex.h"

# define NOT_FOUND -1

char	*find_exec_path(t_cmd_path *cmd_path, char *cmd);
char	*find_exec_path_via_inputmcd(t_cmd_path *cmd_path, char *cmd);
char	*find_exec_absolute_path(t_cmd_path *cmd_path, char *cmd);
bool	split_path_dirs(char **envp, t_cmd_path *cmd_path);
bool	get_cmd_list(int argc, char	**argv, t_cmd_path *cmd_path);
int		cnt_input_cmds(int argc);
int		get_idx_chr(char *str, char c);

#endif