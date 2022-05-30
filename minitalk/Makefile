# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/26 15:11:16 by sayar             #+#    #+#              #
#    Updated: 2021/12/28 16:31:46 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME_C = client

NAME_S = server

NAME_CB = client_bonus

NAME_SB = server_bonus

SRC_C = client.c

SRC_S = server.c

SRC_CB = client_bonus.c

SRC_SB = server_bonus.c

UTILS = minitalk_utils.c minitalk_utils_1.c

OBJ = ${patsubst %.c, %.o, ${UTILS}}

.PHONY : all clean fclean re

all : ${NAME_C} ${NAME_S}

${NAME_C} :
	${CC} ${FLAGS} ${SRC_C} ${UTILS} -o ${NAME_C}

${NAME_S} :
	${CC} ${FLAGS} ${SRC_S} ${UTILS} -o ${NAME_S}

bonus : all
	${CC} ${FLAGS} ${SRC_SB} ${UTILS} -o ${NAME_SB}
	${CC} ${FLAGS} ${SRC_CB} ${UTILS} -o ${NAME_CB}

clean :
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME_C} ${NAME_S} ${NAME_SB} ${NAME_CB}

re : fclean all

