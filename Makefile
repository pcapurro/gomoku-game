# # #==============# # #
# # ### MAKEFILE ### # #
# # #==============# # #

## === VARIABLES === ##

NAME = gomoku

SRCS = srcs/main.cpp \
	srcs/display/Routine.cpp \
	srcs/display/Display.cpp \
	srcs/engine/Engine.cpp \
	srcs/engine/Init.cpp \
	srcs/engine/Tools.cpp \

CXX = c++ \
	-I includes/ \
	-D MAP_WIDTH=19 -D MAP_HEIGHT=19 \
	-D PLAYER1_COLOR=2 -D PLAYER2_COLOR=1

CXXFLAGS = -Wall -Wextra -Werror

SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS = $(SRCS:.cpp=.o)

## === RULES === ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(SFMLFLAGS)

re: fclean all

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
