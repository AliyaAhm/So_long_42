/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:41:30 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 12:16:24 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processor_pointer(unsigned long long ar)
{
	int		len;
	char	*pointer;

	len = 0;
	if (!ar)
	{
		len += ft_putprint("0x0", 3);
		return (len);
	}
	pointer = ft_rnb(ar, 16);
	len = 0;
	len += ft_putprint("0x", 2);
	len += ft_putprint(pointer, ft_strlen(pointer));
	free (pointer);
	return (len);
}
