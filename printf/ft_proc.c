/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:20:09 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:21:52 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_proc(int type, va_list	args)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = len + ft_processor_char(va_arg(args, int));
	else if (type == 's')
		len = len + ft_processor_string(va_arg(args, char *));
	else if (type == 'p')
		len = len + ft_processor_pointer(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len = len + ft_processor_int(va_arg(args, int));
	else if (type == 'u')
		len = len + ft_processor_unit((unsigned int)va_arg(args, unsigned int));
	else if (type == 'x')
		len = len + ft_processor_hex(va_arg(args, unsigned int), 1);
	else if (type == 'X')
		len = len + ft_processor_hex(va_arg(args, unsigned int), 0);
	else if (type == '%')
		len = len + ft_processor_percent();
	return (len);
}
