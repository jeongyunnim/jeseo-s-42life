# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:03:24 by jeseo             #+#    #+#              #
#    Updated: 2022/09/28 21:03:24 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
INC		=	ft_printf.h
SRC		=	./client.c\
			./server.c

OBJ		=	$(SRC:%.c=%.o)
RM		=	rm -f
AR		=	ar rc

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(AR) $@ $^

$(OBJ)	:	$(SRC)
	$(CC) $(CFLAGS) -c $^ -I $(INC)

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re