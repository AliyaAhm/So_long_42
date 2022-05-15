/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstring.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 12:09:24 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 12:09:33 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstring(char *str)
{
	int	len;

	len = 0;
	len += ft_putprint(str, ft_strlen(str));
	return (len);
}
