
CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = FragTrap

SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJDIR = obj

OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

r:$(NAME)
	clear
	@echo "Running $(NAME)..."
	@./$(NAME)
rer: re r

#___for the .SECONDARY rule, it is used to prevent the deletion of the intermediate files.
.SECONDARY: $(OBJS)
