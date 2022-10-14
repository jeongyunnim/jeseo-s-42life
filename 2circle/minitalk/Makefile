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

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

NAME_SERVER			=	server
NAME_CLIENT			=	client

NAME_SERVER_BONUS	=	server_bonus
NAME_CLIENT_BONUS	=	client_bonus

INC					=	ft_minitalk.h

SRC_SERVER			=	./server.c
SRC_CLIENT			=	./client.c

SRC_SERVER_BONUS	=	./server.c
SRC_CLIENT_BONUS	=	./client.c

OBJ_SERVER			=	$(SRC_SERVER:%.c=%.o)
OBJ_CLIENT			=	$(SRC_CLIENT:%.c=%.o)

OBJ_SERVER_BONUS	=	$(SRC_SERVER:%.c=%.o)
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT:%.c=%.o)

RM					=	rm -f
AR					=	ar rc

all		:	$(NAME_SERVER) $(NAME_CLIENT)

bonus	:	$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

$(NAME_SERVER)	:	$(OBJ_SERVER)
	$(AR) $@ $^

$(NAME_CLIENT)	:	$(OBJ_CLIENT)
	$(AR) $@ $^

$(NAME_SERVER_BONUS)	:	$(OBJ_SERVER_BONUS)
	$(AR) $@ $^

$(NAME_CLIENT_BONUS)	:	$(OBJ_CLIENT_BONUS)
	$(AR) $@ $^

$(OBJ_SERVER)	:	$(SRC_SERVER)
	$(CC) $(CFLAGS) -c $^ -I $(INC)

$(OBJ_CLIENT)	:	$(SRC_CLIENT)
	$(CC) $(CFLAGS) -c $^ -I $(INC)

$(OBJ_SERVER_BONUS)	:	$(SRC_SERVER_BONUS)
	$(CC) $(CFLAGS) -c $^ -I $(INC)

$(OBJ_CLIENT_BONUS)	:	$(SRC_CLIENT_BONUS)
	$(CC) $(CFLAGS) -c $^ -I $(INC)


clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re