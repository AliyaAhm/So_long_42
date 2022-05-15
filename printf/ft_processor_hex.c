/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:28:00 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:31:57 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

int	ft_processor_hex(unsigned int i, int height)
{
	char	*hex;
	int		len;
	int		index;

	index = 0;
	len = 0;
	i = (unsigned int)(i + 4294967295 + 1);
	hex = ft_rnb((unsigned long long)i, 16);
	if (height == 0)
	{
		while (hex[index])
		{
			hex[index] = ft_toupper(hex[index]);
			index++;
		}
	}
	len += ft_putprint(hex, ft_strlen(hex));
	free(hex);
	return (len);
}
