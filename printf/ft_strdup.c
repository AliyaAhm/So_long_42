/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:34:44 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 12:44:44 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char			*dst;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	(dst = (char *)malloc(sizeof(char) * (len + 1)));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
