NAME =	mommy_when_i_grow_up_i_want_to_be_a_bureaucrat
SRCS =	main.cpp Bureaucrat.cpp
OBJS =	$(SRCS:.cpp=.o)
CPP98 =	g++ -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP98) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CPP98) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re