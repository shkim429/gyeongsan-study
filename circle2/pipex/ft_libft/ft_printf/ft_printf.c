/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:01:18 by sohuikim          #+#    #+#             */
/*   Updated: 2025/09/15 14:43:46 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(va_list *ap, char format);
int	error_case(char format, int *len);

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				len += write(1, "%", 1);
			if (len == 0 && (error_case(format[i], &len) == 1))
				i++;
			len += parse_format(&ap, format[i]);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}

int	parse_format(va_list *ap, char format)
{
	if (format == 'c')
		return (ft_print_c(va_arg(*ap, int)));
	else if ((format == 'd') || (format == 'i'))
		return (ft_print_id(va_arg(*ap, int)));
	else if (format == 'u')
		return (ft_print_u(va_arg(*ap, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), LOWERCASE));
	else if (format == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), UPPERCASE));
	else if (format == 's')
		return (ft_print_s(va_arg(*ap, char *)));
	else if (format == 'p')
		return (ft_print_p(va_arg(*ap, void *), 0));
	else
		return (0);
}

int	error_case(char format, int *len)
{
	char	*error_map;	

	error_map = "0123456789CILZjlqtz";
	if (ft_strchr(error_map, format))
	{
		*len = -1;
		return (1);
	}
	else
		return (0);
}
