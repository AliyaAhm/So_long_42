/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:44:42 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:46:09 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processor_string(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	len += ft_putprint(str, ft_strlen(str));
	return (len);
}
