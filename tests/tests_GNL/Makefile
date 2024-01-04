# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/19 02:40:49 by ssghioua          #+#    #+#              #
#    Updated: 2023/12/19 02:40:55 by ssghioua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = main.c 

SOURCES_GNL = ../../get_next_line/gnl_v2_single_static/get_next_line.c ../../get_next_line/gnl_v2_single_static/get_next_line_utils.c

NAME = output_test_gnl.a

CCFLAGS = cc -Wall -Werror -Wextra

OBJECTS = ${SOURCES:.c=.o}

OBJECTS_GNL = ${SOURCES_GNL:.c=.o}

HEADER = ../../get_next_line/gnl_v2_single_static/get_next_line.h

all :	${NAME}

.c.o :
	${CCFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME} :	${OBJECTS_GNL} ${OBJECTS} 
	ar -rsc ${NAME} ${OBJECTS} ${OBJECTS_GNL}
		${CCFLAGS} ${NAME} -o run_test_gnl


${OBJECTS_GNL} : ${OBJECTS}
	${CCFLAGS} -c ${SOURCES_GNL}
	mv ./get_next_line.o ./get_next_line_utils.o ../../get_next_line/gnl_v2_single_static/

# ifneq ($(filter-out $@,$(MAKECMDGOALS)), ) 
# 	@echo "NOT INIT"
# BUFFER_SIZE = $(filter-out $@, $(MAKECMDGOALS))
# endif
# ifndef BUFFER_SIZE
# 	@echo "INIT"
# 	${CCFLAGS} -D BUFFER_SIZE=${BUFFER_SIZE} -I ${HEADER} -c ${SOURCES_GNL}
# else
	# endif	

clean :
	rm -f ${OBJECTS} ${OBJECTS_GNL}

fclean :	clean
	rm -f ${NAME} run_test_gnl

re : fclean all



