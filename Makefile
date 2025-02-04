NAME = math-skills

# Find all .cpp files in the current directory and subdirectories
SRC = $(shell find . -name "*.cpp")

# Generate corresponding .o files from .cpp files
OBJ = $(SRC:.cpp=.o)

# Compiler flags
FLAGS = -Wall -Wextra -Werror

# The default target
all: $(NAME)

# Link object files to create the final executable
$(NAME): $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $(NAME)

# Rule for creating object files from source files
# This will match each .o file to its corresponding .cpp file
%.o: %.cpp
	@c++ $(FLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJ)

# Clean object files and the executable
fclean: clean
	@rm -f $(NAME)

# Rebuild the project (clean and then build)
re: fclean all

# Declare phony targets
.PHONY: all clean fclean re
