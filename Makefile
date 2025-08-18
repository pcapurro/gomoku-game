# # #==============# # #
# # ### MAKEFILE ### # #
# # #==============# # #

## === VARIABLES === ##

NAME = gomoku-game

SRCS = srcs/main.cpp \
	srcs/display/Routine.cpp \
	srcs/display/Display.cpp \
	srcs/shell/Routine.cpp \
	srcs/shell/Shell.cpp \
	srcs/engine/Engine.cpp \
	srcs/engine/Checkers.cpp \
	srcs/engine/Init.cpp \
	srcs/engine/Tools.cpp \
	srcs/engine/Print.cpp \

CXX = c++ -I includes/ \
	-D MAP_WIDTH=21 -D MAP_HEIGHT=21 \
	-D PLAYER1_COLOR=2 -D PLAYER2_COLOR=1 \
	-D LINE=5 -D DOUBLE_THREE=0 -D CAPTURE=2

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
