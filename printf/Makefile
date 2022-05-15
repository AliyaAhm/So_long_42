# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 22:35:02 by oshelba           #+#    #+#              #
#    Updated: 2022/05/09 11:14:06 by oshelba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = printf.a

SRCS = ft_printf.c ft_processor_char.c \
ft_processor_hex.c ft_processor_int.c \
ft_processor_percent.c \
ft_processor_pointer.c \
ft_processor_string.c \
ft_processor_unit.c \
ft_putchar.c \
ft_putprint.c\
ft_rnb.c \
ft_moditoa.c \
ft_proc.c \
putstring.c \
ft_strdup.c \
ft_parse_in.c \
ft_strlen.c \
ft_itoa.c \

HEADER = ft_printf.h

OBJS = ${SRCS:%.c=%.o}

CC = clang -g
CFLAGS = -Wall -Wextra -Werror -I ${HEADER}

.PHONY : all clean fclean re

all : ${NAME}

${NAME} : ${OBJS} ${HEADER}
	ar -rcs ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ 

clean :
	rm -f ${OBJS} ${NAME}

fclean : clean
	rm -f ${NAME}

re : fclean all