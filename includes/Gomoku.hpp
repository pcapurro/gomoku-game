#ifndef GOMOKU_HPP
# define GOMOKU_HPP

# include <iostream>
# include <vector>
# include <iostream>

# include <chrono>
# include <iomanip>

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

# include <algorithm>

# ifndef MAP_WIDTH
#  define MAP_WIDTH 19
# endif

# ifndef MAP_HEIGHT
#  define MAP_HEIGHT 19
# endif

# if MAP_WIDTH > 21
#  undef MAP_WIDTH
#  define MAP_WIDTH 19
# endif

# if MAP_HEIGHT > 21
#  undef MAP_HEIGHT
#  define MAP_HEIGHT 19
# endif

# if MAP_WIDTH < 9
#  undef MAP_WIDTH
#  define MAP_WIDTH 19
# endif

# if MAP_HEIGHT < 9
#  undef MAP_HEIGHT
#  define MAP_HEIGHT 19
# endif

# if MAP_WIDTH != MAP_HEIGHT
#  undef MAP_WIDTH
#  undef MAP_HEIGHT
#  define MAP_WIDTH 19
#  define MAP_HEIGHT 19
# endif

# ifndef PLAYER1_COLOR
#  define PLAYER1_COLOR 2
# endif

# ifndef PLAYER2_COLOR
#  define PLAYER2_COLOR 1
# endif

# if PLAYER1_COLOR == PLAYER2_COLOR
#  undef PLAYER1_COLOR
#  undef PLAYER2_COLOR
#  define PLAYER1_COLOR 2
#  define PLAYER2_COLOR 1
# endif

# ifndef LINE
#  define LINE 5
# endif

# if LINE > MAP_WIDTH || LINE > MAP_HEIGHT || LINE < 2
#  undef LINE
#  define LINE 5
# endif

# ifndef DOUBLE_THREE
#  define DOUBLE_THREE 0
# endif

# if DOUBLE_THREE != 1 && DOUBLE_THREE != 0
#  undef DOUBLE_THREE
#  define DOUBLE_THREE 0
# endif

# ifndef CAPTURE
#  define CAPTURE 10
# endif

# if CAPTURE < 2 || CAPTURE > 42
#  undef CAPTURE
#  define CAPTURE 10
# endif

# define END_COLOR "\033[0m"

# define EMPTY 0
# define PLAYER_1 1
# define PLAYER_2 2

using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::chrono::high_resolution_clock;

int		main(const int argc, const char** argv);

#endif
