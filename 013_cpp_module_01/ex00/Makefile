NAME = braiiiiiiinnnzzzz
SRCS = 
OBJS = $(SRCS:.cpp=.o)
CPP98 = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)
$(NAME): $(OBJS)
	$(CPP98) $(OBJS) -o $(NAME)
	
clean:
	rm -f $(OBJS) $(NAME)
	
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
