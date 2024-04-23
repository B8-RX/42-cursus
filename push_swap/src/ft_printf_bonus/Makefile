# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 05:11:01 by ssghioua          #+#    #+#              #
#    Updated: 2024/02/06 05:11:05 by ssghioua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/

OBJ_PATH = ./src/obj/

SOURCES = ${wildcard ${SRC_PATH}*.c}

SOURCES_BONUS = ${SOURCES} ./src/ft_flags_utils_bonus.c

NAME = libftprintf.a

CCFLAGS = cc -Wall -Werror -Wextra

HEADER = ./src/lib/ft_printf.h

OBJECTS = ${patsubst ${SRC_PATH}%.c,${OBJ_PATH}%.o,${SOURCES}}

OBJECTS_BONUS = ${patsubst ${SRC_PATH}%.c,${OBJ_PATH}%.o,${SOURCES_BONUS}}

all : ${NAME}

${OBJ_PATH}%.o : ${SRC_PATH}%.c 
	${CCFLAGS} -I ${HEADER} -c $< -o $@

${NAME} : ${HEADER} ${OBJECTS}
	ar -rsc ${NAME} ${OBJECTS}

bonus :  ${HEADER} ${OBJECTS_BONUS}
	ar -rsc ${NAME} ${OBJECTS_BONUS}

clean : 
	rm -f ${OBJECTS}

fclean : clean
	rm -f ${NAME}

re : fclean all
