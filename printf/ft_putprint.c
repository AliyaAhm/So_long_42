/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:51:05 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:53:53 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putprint(char *str, int pr)
{
	int	len;

	len = 0;
	while (str[len] && len < pr)
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
