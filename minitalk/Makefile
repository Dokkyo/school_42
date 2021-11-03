#############################
#		Programmes			#
#############################
NAME			=	minitalk
SERVER			=	server
CLIENT			=	client
SERVER_BONUS	=	server_bonus
CLIENT_BONUS	=	client_bonus

#############################
#		Compilation			#
#		& Flags				#
#############################
CC		=	gcc $(CFLAGS)
CFLAGS	=	-Wall -Wextra -Werror

IFLAGS	= -I./libft
LFLAGS	= -L./libft

#############################
#		DIRECTORIES &		#
#		Sources Files		#
#############################
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SERVER_FILES = server.c $(LIBFT)
SBONUS_FILES = server_bonus.c $(LIBFT)

CLIENT_FILES = client.c $(LIBFT)
CBONUS_FILES = client_bonus.c $(LIBFT)

#############################
#		MAKE	RULES		#
#############################
$(NAME) : $(SERVER) $(CLIENT)

all:	$(NAME) bonus

bonus :	$(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER) : $(SERVER_FILES)
	$(CC) $(LFLAGS) $(SERVER_FILES) -o $(SERVER)

$(CLIENT) : $(CLIENT_FILES)
	$(CC) $(LFLAGS) $(CLIENT_FILES) -o $(CLIENT)

$(SERVER_BONUS) : $(SBONUS_FILES)
	$(CC) $(LFLAGS) $(SBONUS_FILES) -o $(SERVER_BONUS)

$(CLIENT_BONUS) : $(CBONUS_FILES)
	$(CC) $(LFLAGS) $(CBONUS_FILES) -o $(CLIENT_BONUS)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make -C $(LIBFT_DIR) clean

clean:
	make -C $(LIBFT_DIR) clean
#	$(RM) $(OBJ)

fclean: clean 
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(SERVER)
	$(RM) $(CLIENT)
	$(RM) $(SERVER_BONUS)
	$(RM) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re
