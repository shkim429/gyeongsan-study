/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:24:14 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/11 15:26:24 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_cmd_list_util.h"
#include "ft_libft.h"
#include <stdlib.h>

int	split_path_dirs(char **envp, t_pipe_util *util)
{
	int	i;
	int	n;

	i = 0;
	if (envp == NULL)
		return (FAILURE);
	while (envp[i] != NULL)
	{
		n = get_idx_chr(envp[i], '=');
		if (n != NOT_FOUND)
		{
			if (ft_strncmp(envp[i], "PATH=", n) == 0)
			{
				util->dirs_path = ft_split(&envp[i][n + 1], ':');
				if (util->dirs_path == NULL)
					break ;
				else
					return (SUCCESS);
			}
		}
		i++;
	}
	return (FAILURE);
}

int	get_cmd_list(int argc, char	**argv, t_pipe_util *util)
{
	int		i;
	int		j;

	util->cnt_cmds = cnt_input_cmds(argc);
	util->cmd_list = ft_calloc(util->cnt_cmds + 1, sizeof(*(util->cmd_list)));
	if (util->cmd_list == NULL)
		return (FAILURE);
	i = 2;
	j = 0;
	while (i < argc - 1)
	{
		util->cmd_list[j] = ft_split(argv[i], ' ');
		if (util->cmd_list[j] == NULL)
			return (FAILURE);
		i++;
		j++;
	}
	return (SUCCESS);
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
