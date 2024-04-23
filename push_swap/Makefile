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

SOURCES_BONUS = ${SOURCES}

NAME = pushswap.a

LIB_FTPRINTF_DIR = ./src/ft_printf_bonus

LIB_FTPRINTF = ${LIB_FTPRINTF_DIR}/libftprintf.a

EXE = run_test.out

CCFLAGS = cc -Wall -Werror -Wextra

HEADER = ${SRC_PATH}push_swap.h

OBJECTS = $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SOURCES))

OBJECTS_BONUS = $(patsubst $(SRC_PATH)%.c,$(OBJ_PATH)%.o,$(SOURCES_BONUS))

all : ${NAME}

${OBJ_PATH}%.o : ${SRC_PATH}%.c
	${CCFLAGS} -I ${HEADER} -c $< -o $@

${NAME} : ${LIB_FTPRINTF} ${HEADER} ${OBJECTS}
	ar -rsc ${NAME} ${OBJECTS} 
	${CCFLAGS} ${NAME} -o ${EXE}

${LIB_FTPRINTF} :
	make bonus -C ${LIB_FTPRINTF_DIR}
	cp ${LIB_FTPRINTF} ${NAME}

bonus : ${LIB_FTPRINTF} ${HEADER} ${OBJECTS_BONUS}
	ar -rsc ${NAME} ${OBJECTS_BONUS} 
	${CCFLAGS} ${NAME} -o ${EXE}

clean : 
	rm -f ${OBJECTS} 
	cd ${LIB_FTPRINTF_DIR} && make clean 

fclean : clean
	rm -f ${NAME} ./${EXE}
	cd ${LIB_FTPRINTF_DIR} && make fclean 

re : fclean all

