NAME	= fdf

SRCS	= main.c parse.c parse_utils.c bresenham.c draw.c draw_utils.c cadran1.c cadran2.c free.c close.c

OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})

FL_MLX	= -ldl -L./mlx_linux -lmlx -Lmlx -lm -lXext -lX11 mlx_linux/libmlx.a

LIBFT = libft/libft.a

all:		${NAME}

$(NAME):	${OBJS}
	@make -C ./mlx_linux
	@make -C ./libft
	@gcc -g -Wall -Wextra -Werror -I includes ${OBJS} -o $(NAME) $(LIBFT) $(FL_MLX)

objs/%.o:	%.c fdf.h
	@mkdir -p objs
	@gcc -g -Wall -Werror -Wextra -lmlx -lbass -I includes -o $@ -c $<

clean:
	@make -C ./mlx_linux clean
	rm -rf objs
	rm -f libft/*.o

fclean: clean
	@make -C ./mlx_linux clean
	rm -f libft/libft.a
	rm -f ${NAME}

re:		fclean all

.PHONY: all clean fclean re
