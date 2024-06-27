# (Variables)
CLIENT = client

SERVER = server

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I libft/includes

# (Reglas)
all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) client.c
	@gcc $(FLAGS) $(INCLUDES) -o $(CLIENT) client.c $(LIBFT)

$(SERVER): $(LIBFT) server.c
	@gcc $(FLAGS) $(INCLUDES) -o $(SERVER) server.c $(LIBFT)

$(CLIENT_BONUS): $(LIBFT) client.c
	@gcc $(FLAGS) $(INCLUDES) -o $(CLIENT_BONUS) client_bonus.c $(LIBFT)

$(SERVER_BONUS): $(LIBFT) server.c
	@gcc $(FLAGS) $(INCLUDES) -o $(SERVER_BONUS) server_bonus.c $(LIBFT)

$(LIBFT):
	@make -C libft
	@echo 📝 Compilating libraries and client/server resources...

clean:
	@make -C libft clean
	@echo 🗑️​ Deleting ".o" files only...

fclean: clean
	@make -C libft fclean
	@rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo 🗑️​ Deleting all files and client/server resources...

re: fclean all

bonus: $(CLIENT_BONUS) $(SERVER_BONUS) 

.PHONY: all clean fclean re
