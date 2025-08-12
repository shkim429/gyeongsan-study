/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:09:23 by sohuikim          #+#    #+#             */
/*   Updated: 2025/08/12 01:59:11 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *format, ...);
int				parse_format(va_list *ap, char format);
int				ft_print_c(char c);
int				ft_print_id(int id);
int				ft_print_u(unsigned int u);
int				ft_print_hex(unsigned int x_num, int uppercase);
int				ft_print_s(char *str);
int				ft_print_p(void *ptr, int uppercase);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s);
char			*ft_itoa(int n);
char			*ft_utoa(unsigned int n);
char			*ft_utoa_base(uintptr_t n, uintptr_t base, int uppercase);
void			*ft_memset(void *s, int c, size_t n);

#endif