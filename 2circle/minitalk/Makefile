# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeseo <jeseo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/28 21:03:24 by jeseo             #+#    #+#              #
#    Updated: 2022/10/18 16:56:45 by jeseo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror

NAME_SERVER			=	server
NAME_CLIENT			=	client

NAME_SERVER_BONUS	=	server_bonus
NAME_CLIENT_BONUS	=	client_bonus

INC					=	ft_minitalk.h
INC_BONUS			=	ft_minitalk_bonus.h

SRC_SERVER			=	./server.c\
						./ft_minitalk_util.c 
SRC_CLIENT			=	./client.c\
						./ft_minitalk_util.c 

SRC_SERVER_BONUS	=	./server_bonus.c\
						./ft_minitalk_util_bonus.c 
SRC_CLIENT_BONUS	=	./client_bonus.c\
						./ft_minitalk_util.c 

OBJ_SERVER			=	$(SRC_SERVER:%.c=%.o)
OBJ_CLIENT			=	$(SRC_CLIENT:%.c=%.o)

OBJ_SERVER_BONUS	=	$(SRC_SERVER_BONUS:%.c=%.o)
OBJ_CLIENT_BONUS	=	$(SRC_CLIENT_BONUS:%.c=%.o)

RM					=	rm -f

all		:	$(NAME_SERVER) $(NAME_CLIENT)

bonus	:	$(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)


$(NAME_SERVER)	:	$(OBJ_SERVER)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC)

$(NAME_CLIENT)	:	$(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC)

$(NAME_SERVER_BONUS)	:	$(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_BONUS)

$(NAME_CLIENT_BONUS)	:	$(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ -I $(INC_BONUS)

clean	:
	$(RM) $(OBJ_CLIENT) $(OBJ_CLIENT_BONUS) $(OBJ_SERVER) $(OBJ_SERVER_BONUS)

fclean	:	clean
	$(RM) $(NAME_CLIENT) $(NAME_CLIENT_BONUS) $(NAME_SERVER) $(NAME_SERVER_BONUS)

re		:	fclean all

.PHONY	:	all clean fclean re