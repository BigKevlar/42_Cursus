NAME =	i_dont_want_to_set_the_world_on_fire
SRCS =	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
OBJS =	$(SRCS:.cpp=.o)
CPP98 =	g++ -Wall -Wextra -Werror -std=c++98

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