NAME = so_long

SRCS		= 	src/main.c				\
				src/ft_check.c		\
				src/ft_draw_map.c	\
				src/ft_init_images.c	\
				src/ft_key_press.c 	\
				src/ft_parsing.c		\

SRCS_B		= 	src_bonus/main_bonus.c   \
				src_bonus/ft_check_bonus.c \
				src_bonus/ft_draw_map_bonus.c	\
				src_bonus/ft_parsing_bonus.c	\
				src_bonus/ft_key_press_bonus.c	\
				src_bonus/ft_init_images_bonus.c		\

OBJ		= $(SRCS:.c=.o)

OBJ_B		= $(SRCS_B:%.c=%.o)

LIB			= libft/libft.a minilibx/libmlx.a printf/printf.a

INCLUDE		= include/

HEADER		= so_long.h

CC			= clang -g

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

MLX 		= -framework OpenGL -framework AppKit -lmlx

#---------------------------------------------------------------------------------
RED		=	\033[1;31m
BLUE	=	\033[1;34m
YELLOW	=	\033[1;33m
WHITE	=	\033[1;32m
PUPURE	=	\033[1;35m
GRY		=	\033[1;30m
TURQUOISE =	\033[36;1m
END		=	\033[0m
#---------------------------------------------------------------------------------

.PHONY:		all	clean	fclean	re	bonus libft printf

all:		libft printf mlx $(NAME)

libft:
			@$(MAKE) -C libft/

printf:
			@$(MAKE) -C printf/

mlx:
			@$(MAKE) -C minilibx/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) $(MLX) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

%.o :		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

bonus:		mlx libft printf $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) $(MLX) -o $(NAME)
			@echo "$(TURQUOISE)\n< Complited $(NAME) >\n$(END)"

clean:
			@$(RM) $(OBJ) $(OBJ_B) $(NAME)
			@$(MAKE) -C libft/ clean
			@$(MAKE) -C minilibx/ clean
			@$(MAKE) -C printf/ clean
			@echo "$(YELLOW)\n< Cleaning succeed >\n$(END)"

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(MAKE) -C printf/ fclean
			@$(RM) $(NAME)
			@echo "$(YELLOW)\n< All created files were deleted >\n$(END)"

re:			fclean all
			@echo "$(BLUE)\n< Remake done >\n$(END)"