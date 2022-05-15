/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:15:37 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:18:17 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_in(const char *str, va_list args)
{
	int	leng;
	int	i;

	leng = 0;
	i = 0;
	while (1)
	{
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			if ((str[++i] == 'c') || (str[i] == 's') || (str[i] == 'p')
				|| (str[i] == 'd') || (str[i] == 'i') || (str[i] == 'u')
				|| (str[i] == 'x') || (str[i] == 'X') || (str[i] == '%'))
				leng += ft_proc(str[i], args);
		}
		else if (str[i] != '%')
		{
			ft_putchar(str[i]);
			leng++;
		}
		i++;
	}
	return (leng);
}
