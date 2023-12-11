

SOURCES = main.c \

NAME = output_ftprintf.a

CCFLAGS = cc -Wall -Wextra -Werror

LIB_PRINTF_PATH = ../ft_printf

LIB_PRINTF  = ${LIB_PRINTF_PATH}/libftprintf.a

OBJECTS = ${SOURCES:.c=.o}

HEADER = ../ft_printf/libftprintf.h

all : ${NAME}

.c.o :
	${CCFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME} :	${LIB_PRINTF} ${OBJECTS}
	cp ${LIB_PRINTF} ${NAME}
		ar -rsc ${NAME} ${OBJECTS}
		${CCFLAGS} ${NAME} -o run_test

${LIB_PRINTF} :
	make -C ${LIB_PRINTF_PATH} all

clean :	
	make -C ${LIB_PRINTF_PATH} clean
	rm -f ${OBJECTS}

fclean :	clean
	make -C ${LIB_PRINTF_PATH} fclean
	rm -f ${NAME} run_test

re :	fclean all

