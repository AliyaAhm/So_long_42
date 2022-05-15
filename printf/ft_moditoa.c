/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moditoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 08:45:13 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 16:24:48 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	ft_znak(unsigned int n)
{
	int	znak;

	znak = 1;
	if (n < 0)
		znak = -1;
	return (znak);
}

char	*ft_moditoa(unsigned int n)
{
	int				len;
	int				znak;
	long			nbr;
	char			*str;

	nbr = n;
	znak = ft_znak(nbr);
	len = ft_len(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (char)((n % 10) * ((2 * (n > 0)) - 1) + 48);
		n = n / 10;
	}
	len--;
	if (znak < 0)
		str[len] = '-';
	return (str);
}
