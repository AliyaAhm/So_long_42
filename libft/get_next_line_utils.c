/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:51:41 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/08 10:09:36 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *s)
{
	char	*dst;
	int		i;
	int		len;

	i = 0;
	if (!(*s))
		return (NULL);
	len = ft_strlen_gnl(s);
	dst = (char *)malloc(sizeof(char) * (len + 2));
	if (!dst)
		return (NULL);
	while (i < (len))
	{
		dst[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		dst[i] = '\n';
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin_gnl(char *n_line, char *buf)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!n_line)
	{
		n_line = (char *)malloc(1 * sizeof(char));
		n_line[0] = '\0';
	}
	if (!n_line || !buf)
		return (NULL);
	str = (char *)malloc((ft_strlen(n_line) + ft_strlen(buf)
				+ 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (n_line)
		while (n_line[++i] != '\0')
			str[i] = n_line[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[ft_strlen(n_line) + ft_strlen(buf)] = '\0';
	free(n_line);
	return (str);
}
