NAME		=	push_swap

CFLAGS 		=	-Wall -Wextra -Werror

CC			=	gcc

SRCS		=	dlist.c instructions.c instructions2.c print.c main.c sort.c three_random_case.c utils_errors.c utils_radix.c

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	: $(OBJS)
			$(CC) -o $(NAME) $(OBJS)

main.o: push_swap.h
%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all
