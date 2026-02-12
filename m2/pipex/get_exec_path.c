/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 02:05:42 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/13 02:12:47 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_exec_path.h"
#include "ft_libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*find_exec_path(t_cmd_path *cmd_path, char *cmd)
{
	int		is_slash;
	char	*exec_path;

	is_slash = get_idx_chr(cmd, '/');
	if (is_slash >= 0)
	{
		exec_path = find_exec_absolute_path(cmd_path, cmd);
		return (exec_path);
	}
	else
	{
		exec_path = find_exec_path_via_inputmcd(cmd_path, cmd);
		return (exec_path);
	}
}

char	*find_exec_path_via_inputmcd(t_cmd_path *cmd_path, char *cmd)
{
	char	*path_prefix;
	char	*exec_path;
	int		i;

	i = 0;
	while (cmd_path->dirs_path[i] != NULL)
	{
		path_prefix = ft_strjoin(cmd_path->dirs_path[i], "/");
		exec_path = ft_strjoin(path_prefix, cmd);
		free(path_prefix);
		if (access(exec_path, X_OK) != -1)
			return (exec_path);
		else
		{
			free(exec_path);
			i++;
		}
	}
	return (NULL);
}

char	*find_exec_absolute_path(t_cmd_path *cmd_path, char *cmd)
{
	int	i;

	i = 0;
	if (access(cmd, X_OK) != -1)
		return (cmd);
	return (NULL);
}
