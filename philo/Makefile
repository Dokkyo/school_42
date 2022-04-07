NAME	= philo

SRCS	= main.c threads.c errors.c parsing.c parsing_utils.c state.c state_utils.c time.c

OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})

all:		${NAME}

$(NAME):	${OBJS}
	@gcc -g -Wall -Wextra -Werror -I includes ${OBJS} -o $(NAME) -lpthread

objs/%.o:	%.c philo.h
	@mkdir -p objs
	@gcc -g -Wall -Werror -Wextra -I includes -o $@ -c $<

clean:
	rm -rf objs

fclean: clean
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
