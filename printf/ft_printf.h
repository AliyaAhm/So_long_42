/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:56:51 by oshelba           #+#    #+#             */
/*   Updated: 2021/11/27 16:25:57 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_pr_width(int width, int minus, int zero);
int		ft_processor_char(char c);
int		ft_processor_hex(unsigned int i, int height);
int		ft_processor_int(int i);
int		ft_processor_percent(void);
int		ft_processor_pointer(unsigned long long ar);
int		ft_processor_string(char *str);
int		ft_processor_unit(unsigned int unit);
void	ft_putchar(int c);
int		ft_putprint(char *str, int pr);
int		ft_proc(int type, va_list args);
int		putstring(char *str);
char	*ft_moditoa(unsigned int n);
char	*ft_rnb(unsigned long long rnb, int base);
int		flag_precision(const char *str, int i, va_list args);
int		ft_parse_in(const char *str, va_list args);
char	*ft_strdup(const char *s);
int		ft_toupper(int c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

#endif
