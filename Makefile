NAME = math-skills
SRC = $(shell find . -name "*.cpp")
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME)
%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
