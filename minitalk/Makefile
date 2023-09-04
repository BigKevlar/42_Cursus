# (Variables)
CLIENT = client

SERVER = server

LIBFT = libft/libft.a

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I libft/includes

# (Reglas)
all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT) client.c
	@gcc $(FLAGS) $(INCLUDES) -o $(CLIENT) client.c $(LIBFT)

$(SERVER): $(LIBFT) server.c
	@gcc $(FLAGS) $(INCLUDES) -o $(SERVER) server.c $(LIBFT)

$(LIBFT):
	@make -C libft
	@echo 📝 Compilating libraries and client/server resources...

clean:
	@make -C libft clean
	@echo 🗑️​ Deleting ".o" files only...

fclean: clean
	@make -C libft fclean
	@rm -rf $(CLIENT) $(SERVER)
	@echo 🗑️​ Deleting all files and client/server resources...

re: fclean all

.PHONY: all clean fclean re
