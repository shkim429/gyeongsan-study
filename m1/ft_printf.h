/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:09:23 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/02 02:45:35 by sohuikim         ###   ########.fr       */
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

size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
int				ft_printf(const char *format, ...);
void			*ft_memset(void *s, int c, size_t n);
int				arg_print(t_value *info, va_list ap);
void			parse_format(t_value *info, char format);
int				ft_print_c(char c);
int				ft_print_id(int id);
int				ft_print_u(unsigned int u);
int				ft_print_s(char *str);
#endif