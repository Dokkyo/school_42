NAME		=	libftprintf.a

CFLAGS 		=	-Wall -Wextra -Werror -c

CC			=	gcc

SRCS		=	ft_printf.c utils.c anytoa.c conversions.c conversions_nbrs.c

OBJS		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	: $(OBJS)
			ar crs $@ $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@
		
clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all
