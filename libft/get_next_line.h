/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 23:59:38 by oshelba           #+#    #+#             */
/*   Updated: 2022/05/09 10:36:43 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*ft_new_line(char *s_line);
char	*line_read(int fd, char *s_line);
char	*ft_strjoin_gnl(char *n_line, char *buf);
size_t	ft_strlen(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strdup_gnl(char *s);
size_t	ft_strlen_gnl(char *s);

#endif
