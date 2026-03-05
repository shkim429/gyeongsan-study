/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:47:14 by sohuikim          #+#    #+#             */
/*   Updated: 2026/02/12 18:21:34 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_FILE_H
# define OPEN_FILE_H

# include "pipex.h"

bool	open_infile(char **argv, t_pipe_util *pipe_util);
bool	open_outfile(char **argv, t_pipe_util *pipe_util);

#endif