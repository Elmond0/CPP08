NAME	= mutantstack

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) && echo "\033[32m$(NAME) created.\033[0m"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) && echo "\033[31m$(NAME) wiped.\033[0m"

re: fclean all

.PHONY: all clean fclean re
