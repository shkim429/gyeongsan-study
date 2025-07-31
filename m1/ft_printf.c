/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohuikim <sohuikim@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:01:18 by sohuikim          #+#    #+#             */
/*   Updated: 2025/07/31 16:16:09 by sohuikim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(t_value *info, char format)
{
	if (format == 'c')
		info->type = 'c';
	else if ((format == 'd') || (format == 'i'))
		info->type = 'd';
	else if (format == 'u')
		info->type = 'u';
	else if (format == 'x')
		info->type = 'x';
	else if (format == 'X')
		info->type = 'X';
	else if (format == 's')
		info->type = 's';
	else if (format == 'p')
		info->type = 'p';
}

int	print_type(t_value *info)
{
	if (info->type == 'c')
		return (ft_print_c(info->c));
	else if (info->type == 'd')
		return (ft_print_id(info->id));
	else
		return (-1);

}

void	arg_type(t_value *info, va_list ap)
{
	if (info->type == 'c')
		info->c = va_arg(ap, int);
	else if (info->type == 'd')
		info->id = va_arg(ap, int);
	else if ((info->type == 'u') || (info->type == 'x') || (info->type == 'X'))
		info->ux = va_arg(ap, unsigned int);
	else if (info->type == 's')
		info->s = va_arg(ap, char *);
	else if (info->type == 'p')
		info->p = va_arg(ap, void *);
}

int	ft_printf(const char *format, ...)
{
	t_value	info;
	va_list	ap;
	int		i;
	int		len;

	va_start(ap, format);
	i = 0;
	len = 0;
	ft_memset(&info, 0, sizeof(t_value));
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			parse_format(&info, format[i]);
			arg_type(&info, ap);
			len += print_type(&info);
		}
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return (len);
}

