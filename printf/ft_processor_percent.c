/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_percent.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:38:48 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 09:40:58 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_processor_percent(void)
{
	int	len;

	len = 0;
	len += ft_putprint("%", 1);
	return (len);
}
