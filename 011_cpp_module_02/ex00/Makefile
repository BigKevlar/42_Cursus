NAME =	my_first_class_in_orthodox_canonical_form
SRCS =	main.cpp Fixed.cpp
OBJS =	$(SRCS:.cpp=.o)
CPP98 =	c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)
$(NAME): $(OBJS)
	$(CPP98) $(OBJS) -o $(NAME)
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re