#############################
#	Programmes          #
#############################
#NAME			=	so_long

#############################
#    Compilation & Flags    #
#############################
#CC	=	gcc $(CFLAGS)
#CFLAGS	=	-Wall -Wextra -Werror

#IFLAGS	= -I./libft -I./mlx_linux
#LFLAGS	= -L./libft -L./mlx_linux

#############################
#		DIRECTORIES &		#
#		Sources Files		#
#############################
#LIBFT_DIR	= ./libft
#LIBFT		= $(LIBFT_DIR)/libft.a

#MLX_DIR	= ./mlx_linux
#MLX		= $(MLX_DIR)/libmlx.a

#SOLONG_FILES = main.o $(LIBFT) $(MLX)

#############################
#	MAKE	RULES       #
#############################

#all:	$(NAME)

#$(NAME) : $(SOLONG_FILES)
#	$(CC) $(LFLAGS) -ldl -L./mlx_linux -lmlx -Lmlx -lm -lXext -lX11 -Imlx $(SOLONG_FILES) -o $(NAME)

#%.o: %.c
#	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

#$(MLX):
#	make -C $(MLX_DIR)
#	make -C $(MLX_DIR)

#$(LIBFT):
#	make -C $(LIBFT_DIR)
#	make -C $(LIBFT_DIR)

#clean:
#	make -C $(LIBFT_DIR)
#	make -C $(MLX_DIR)
#	$(RM) $(OBJ)

#fclean: clean
#	make -C $(LIBFT_DIR) fclean
#	make -C $(MLX_DIR) clean
#	$(RM) $(NAME)

#re: fclean all

NAME	= fdf

SRCS	= main.c parse.c parse_utils.c bresenham.c draw.c

OBJS	= ${SRCS:.c=.o}
OBJS	:= $(addprefix objs/,${OBJS})

FL_MLX	= -ldl -L./mlx_linux -lmlx -Lmlx -lm -lXext -lX11 mlx_linux/libmlx.a

LIBFT = libft/libft.a

all:		${NAME}

$(NAME):	${OBJS}

	@make -C ./mlx_linux
	@make -C ./libft
	@gcc -g -Wall -Wextra -Werror -I includes ${OBJS} -o $(NAME) $(LIBFT) $(FL_MLX)

objs/%.o:	%.c
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
