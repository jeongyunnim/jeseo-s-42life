# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/04 15:08:56 by jeseo             #+#    #+#              #
#    Updated: 2022/08/06 16:04:14 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
NAME	=	libftprintf.a
INC		=	ft_printf.h
SRC		=	./ft_printf.c\
			./ft_htoa.c\
			./ft_itoa.c\
			./ft_strdup.c\
			./ft_strlen.c\
			./ft_strupper.c\

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