/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:09:23 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/30 16:26:50 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_value
{
	char			type;
	char			c;
	int				id;
	unsigned int	ux;
	char			*s;
	void			*p;
}	t_value;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_printf(const char *format, ...);
void	*ft_memset(void *s, int c, size_t n);
int		arg_print(t_value *info, va_list ap);
void	parse_format(t_value *info, char format);
int		print_c(char c);
int		print_id(int id);
#endif