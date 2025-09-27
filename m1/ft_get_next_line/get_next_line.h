/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 01:25:17 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/27 16:49:55 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strcut(char *buffer, int *offset);
char	*append_str(char *cut_str);
int	get_idx_find_first_chr(char	*buffer, int find_chr);
char	*ft_realloc(char *stash, size_t capacity_stash, size_t need_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*update_stash(char *buffer, int *offset);
char	*ft_strdup(const char *s);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif