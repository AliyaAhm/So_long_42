/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:46:52 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/07 16:43:09 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*line_read(int fd, char *s_line)
{
	char	*buf;
	int		n_b;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	n_b = 1;
	while (!ft_strchr(s_line, '\n') && n_b > 0)
	{
		n_b = read(fd, buf, BUFFER_SIZE);
		if (n_b == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[n_b] = '\0';
		s_line = ft_strjoin_gnl(s_line, buf);
	}
	free(buf);
	return (s_line);
}

char	*ft_new_line(char *s_line)
{
	int		i;
	int		j;
	char	*str;

	i = ft_strlen_gnl(s_line);
	if (!s_line[i])
	{
		free(s_line);
		return (NULL);
	}
	j = (ft_strlen(s_line) - i + 1);
	str = (char *)malloc(sizeof(char) * j);
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (s_line[i])
		str[j++] = s_line[i++];
	str[j] = '\0';
	free(s_line);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*n_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	n_line = line_read(fd, n_line);
	if (!n_line)
		return (NULL);
	line = ft_strdup_gnl(n_line);
	n_line = ft_new_line(n_line);
	return (line);
}
