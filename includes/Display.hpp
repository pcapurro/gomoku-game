#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <SFML/Graphics.hpp>

# include "Engine.hpp"
# include "Ai.hpp"

# define WINDOW_W (MAP_WIDTH * 800) / 19
# define WINDOW_H (MAP_HEIGHT * 750) / 19

void	centerWindow(sf::RenderWindow& window);
void	drawMap(sf::RenderWindow& window, Engine* engine);

void	routine(void* engine, void* ai);

#endif
