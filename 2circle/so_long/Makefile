# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 15:08:56 by jeseo             #+#    #+#              #
#    Updated: 2022/11/11 20:40:13 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3
MLX_FLAGS 	= 	-Lmlx -lmlx -framework OpenGL -framework Appkit
NAME		=	so_long
INC			=	so_long.h
SRC			=	./so_long.c \
				./get_next_line.c\
				./get_next_line_utils.c\
				./pars_map.c\

OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f
AR		=	ar rc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -I $(INC) -o $@

$(OBJ)	:	$(SRC)
	$(CC) $(CFLAGS) -c $^ -I $(INC)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re