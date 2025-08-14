# # #==============# # #
# # ### MAKEFILE ### # #
# # #==============# # #

## === VARIABLES === ##

NAME = gomoku

SRCS = srcs/main.cpp \
	srcs/core/Ai.cpp \
	srcs/core/Engine.cpp \
	srcs/core/Init.cpp \
	srcs/core/Tools.cpp \

CXX = c++ \
	-I includes/ \
	-D MAP_WIDTH=19 -D MAP_HEIGHT=19 \
	-D PLAYER1_COLOR=2 -D PLAYER2_COLOR=1

CXXFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

## === RULES === ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
