
NAME = serialization

SRC = main.cpp Serializer.cpp
OBJ = $(SRC:.cpp=.o)

CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

%.o	: %.cpp
	@$(CPP) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

all	: $(NAME)

clean :
	@rm -rf $(OBJ)
fclean: clean
	@rm -rf $(NAME)
re: fclean all

.PHONY : all clean fclean re