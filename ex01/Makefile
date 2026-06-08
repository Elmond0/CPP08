NAME	= span

CXX		= c++
CXXFLAGS= -Wall -Wextra -Werror -std=c++98

SRCS	= main.cpp Span.cpp
OBJS	= $(SRCS:.cpp=.o)

all:
	@$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME) && echo "\033[32m$(NAME) created.\033[0m"

clean:

fclean: clean
	@rm -f $(NAME) && echo "\033[31m$(NAME) wiped.\033[0m"

re: fclean all

.PHONY: all clean fclean re
