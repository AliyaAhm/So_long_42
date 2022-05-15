/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rnb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:54:49 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:55:51 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*treat_base(unsigned long long rnb, int base,
char *n, int len)
{
	while (rnb != 0)
	{
		if ((rnb % base) < 10)
			n[len] = (rnb % base) + 48;
		else
			n[len] = (rnb % base) + 87;
		rnb /= base;
		len--;
	}
	return (n);
}

char	*ft_rnb(unsigned long long rnb, int base)
{
	char				*n;
	unsigned long long	buf_rnb;
	int					len;

	n = 0;
	len = 0;
	buf_rnb = rnb;
	if (rnb == 0)
		return (ft_strdup("0"));
	while (rnb != 0)
	{
		rnb /= base;
		len++;
	}
	n = malloc(sizeof(char) * (len + 1));
	if (!n)
		return (0);
	n[len] = '\0';
	n = treat_base(buf_rnb, base, n, (len - 1));
	return (n);
}
