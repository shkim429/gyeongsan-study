/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:09:23 by sohuikim          #+#    #+#             */
/*   Updated: 2026/01/14 05:50:29 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# define  LOWERCASE 0
# define UPPERCASE 1

int				ft_printf(const char *format, ...);
int				parse_format(va_list *ap, char format);
int				ft_print_c(char c);
int				ft_print_id(int id);
int				ft_print_u(unsigned int u);
int				ft_print_hex(unsigned int x_num, int uppercase);
int				ft_print_s(char *str);
int				ft_print_p(void *ptr, int uppercase);
char			*ft_utoa(unsigned int n);
char			*ft_utoa_base(uintptr_t n, uintptr_t base, int uppercase);

#endif