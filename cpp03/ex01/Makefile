CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)
NAME = ScavTrap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
