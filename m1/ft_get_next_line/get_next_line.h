/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:25:17 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/21 20:03:52 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

char	*get_next_line(int fd);


#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif