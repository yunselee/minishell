# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 16:09:04 by yunselee          #+#    #+#              #
#    Updated: 2022/03/17 21:18:05 by yunselee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME = allow_function.a

SOURCES =	dir.c \
			dup.c \
			fork.c \
			kill.c \
			open.c \
			read.c \
			wait.c \
			chdir.c \
			dtat.c \
			execve.c \
			getcwd.c \
			malloc.c \
			pipe.c \
			unlink.c \
			write.c \

OBJ		= ${SOURCES:.c=.o}

%.o : %.c
	${CC} ${CFLAGS} -c $^ -o $@

$(NAME)	: ${OBJ}
	ar rc $@ $^

all : ${NAME}


clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf ${NAME}

re : fclean	all

.PHONY: all  clean fclean re
