/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:32:31 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:37:42 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processor_int(int i)
{
	int		len;
	char	*string;

	len = 0;
	if (i == 0)
	{
		len += ft_putprint("0", 1);
		return (len);
	}
	string = ft_itoa(i);
	len = ft_putprint(string, ft_strlen(string));
	free(string);
	return (len);
}
