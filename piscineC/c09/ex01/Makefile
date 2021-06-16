# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naben-za <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/30 10:15:35 by naben-za          #+#    #+#              #
#    Updated: 2021/03/30 11:42:02 by naben-za         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCS		=	$(addprefix ${FOLDER}/, ft_putchar.c ft_strlen.c ft_swap.c ft_putstr.c ft_strcmp.c)
OBJS		=	${SRCS:.c=.o}
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
HEADER		=	includes
FOLDER		=	srcs
RM			=	rm -f

${NAME}:	${OBJS}
					ar -rcs ${NAME} ${OBJS}

all:		${NAME}

%.o: %.c
					${CC} -c ${CFLAGS} -o $@ $< -I ${HEADER}


clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} libft.a

re:			fclean all
