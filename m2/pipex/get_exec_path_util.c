/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_path_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:00:59 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:13:05 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_exec_path.h"
#include "ft_libft.h"
#include <stdlib.h>

bool	split_path_dirs(char **envp, t_cmd_path *cmd_path)
{
	int	i;
	int	n;

	i = 0;
	if (envp == NULL)
		return (false);
	while (envp[i] != NULL)
	{
		n = get_idx_chr(envp[i], '=');
		if (n != NOT_FOUND)
		{
			if (ft_strncmp(envp[i], "PATH=", n) == 0)
			{
				cmd_path->dirs_path = ft_split(&envp[i][n + 1], ':');
				if (cmd_path->dirs_path == NULL)
					break ;
				else
					return (true);
			}
		}
		i++;
	}
	return (false);
}

bool	get_cmd_list(int argc, char	**argv, t_cmd_path *cmd_path)
{
	int		i;
	int		j;

	cmd_path->cnt_cmds = cnt_input_cmds(argc);
	cmd_path->cmd_list = ft_calloc(cmd_path->cnt_cmds + 1, \
						sizeof(*(cmd_path->cmd_list)));
	if (cmd_path->cmd_list == NULL)
		return (false);
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		cmd_path->cmd_list[j] = ft_split(argv[i], ' ');
		if (cmd_path->cmd_list[j] == NULL)
			return (false);
		i++;
		j++;
	}
	return (true);
}

int	cnt_input_cmds(int argc)
{
	int	cnt_cmds;
	int	i;

	cnt_cmds = 0;
	i = 2;
	while (i < argc - 1)
	{
		i++;
		cnt_cmds++;
	}
	return (cnt_cmds);
}

int	get_idx_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c)
	{
		if (str[i] == '\0')
			return (NOT_FOUND);
		i++;
	}
	return (i);
}
