/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_unit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:47:00 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:48:55 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processor_unit(unsigned int unit)
{
	char	*unit_str;
	int		unit1;
	int		len;

	len = 0;
	unit1 = (unsigned int)(unit + 4294967295 + 1);
	unit_str = ft_moditoa(unit1);
	len = ft_putprint(unit_str, ft_strlen(unit_str));
	free (unit_str);
	return (len);
}
