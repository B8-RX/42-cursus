# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssghioua <ssghioua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 19:32:25 by ssghioua          #+#    #+#              #
#    Updated: 2023/12/10 19:32:30 by ssghioua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = ft_printf.c ft_strlen.c ft_print_char.c ft_print_str.c ft_print_nbr.c ft_print_hexa.c ft_handle_format.c \

NAME = libft.a

CCFLAGS = cc -Wall -Werror -Wextra

HEADER = libft.h

OBJECTS = ${SOURCES:.c=.o}

all : ${NAME}

.c.o :
	${CCFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${NAME} :	${OBJECTS}
	ar -rsc ${NAME} ${OBJECTS}

clean :
	rm -f ${OBJECTS}

fclean : clean
	rm -f ${NAME}

re :	fclean all
