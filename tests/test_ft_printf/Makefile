

SOURCES = main.c \

NAME = main_ftprintf.a

CCFLAGS = cc -Wall -Wextra -Werror

LIB_PRINTF_PATH = ../ft_printf

LIB_PRINTF  = ${LIB_PRINTF_PATH}/libft.a

OBJECTS = ${SOURCES:.c=.o}

HEADER = ../ft_printf/libft.h

all : ${NAME}

.c.o :
	${CCFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME} :	${LIB_PRINTF} ${OBJECTS}
	cp ${LIB_PRINTF} ${NAME}
		ar -rsc ${NAME} ${OBJECTS}

${LIB_PRINTF} :
	make -C ${LIB_PRINTF_PATH} all

clean :	
	make -C ${LIB_PRINTF_PATH} clean
	rm -f ${OBJECTS}

fclean :	clean
	make -C ${LIB_PRINTF_PATH} fclean
	rm -f ${NAME}

re :	fclean all

