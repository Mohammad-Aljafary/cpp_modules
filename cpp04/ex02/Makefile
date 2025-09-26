CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp Dog.cpp Cat.cpp Animal.cpp Brain.cpp
OBJDIR = obj
DEP = $(OBJ:%.o=%.d)
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
NAME = Animal

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)