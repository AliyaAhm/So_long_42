/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 16:18:08 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 16:20:51 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int			len;
	const char	*s;
	va_list		ap;

	len = 0;
	s = ft_strdup(str);
	va_start(ap, str);
	len += ft_parse_in(s, ap);
	va_end(ap);
	free((char *)s);
	return (len);
}
