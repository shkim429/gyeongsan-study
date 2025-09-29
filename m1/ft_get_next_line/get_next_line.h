/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:25:17 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/30 04:02:57 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);
char	*ft_strcut(char *buffer, int *offset);
char	*append_str(char *pre_stash, char *cut_str);
int		get_idx_find_first_chr(char	*buffer, int find_chr);
char	*ft_remalloc(char *stash, size_t need_capacity);
char	*end_get_next_line(char *line, char *stash);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*update_stash(char *buffer, int *offset);
char	*ft_strdup(const char *s);
#endif