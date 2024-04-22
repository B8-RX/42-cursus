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

SOURCES = ./push_swap/ft_split.c ./push_swap/push_swap.c ./push_swap/list_utils.c ./push_swap/sort_functions.c ./push_swap/list_management.c ./push_swap/push_swap_utils.c

SOURCES_BONUS = ${SOURCES}

NAME = pushswap.a

EXE = exe.out

CCFLAGS = cc -Wall -Werror -Wextra

HEADER = ./push_swap/push_swap.h

OBJECTS = ${SOURCES:.c=.o}

OBJECTS_BONUS = ${SOURCES_BONUS:.c=.o}

all : ${NAME}

.c.o :
	${CCFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}
	mv ./push_swap/*.o ./push_swap/dist/

${NAME} : ${HEADER} ${OBJECTS}
	ar -rsc ./push_swap/archive/${NAME} ./push_swap/dist/*.o
	${CCFLAGS} ./push_swap/archive/${NAME} -o ${EXE}

bonus :  ${HEADER} ${OBJECTS_BONUS}
	ar -rsc ${NAME} ./push_swap/dist/*.o 

clean : 
	rm -f ./push_swap/dist/*.o

fclean : clean
	rm -f ./push_swap/archive/${NAME}
	rm -f ./${EXE}

re : fclean all
