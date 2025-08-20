#ifndef DISPLAY_HPP
# define DISPLAY_HPP

# include <SFML/Graphics.hpp>

# include "Engine.hpp"

# define WINDOW_W (MAP_WIDTH * 800) / 19
# define WINDOW_H (MAP_HEIGHT * 800) / 19

class Display
{
	public:
		Display(void) = default;
		Display(const Display& original) = delete;
		~Display(void) = default;

		void		centerWindow(sf::RenderWindow& window);
		sf::Color	getPlayerColor(const int player);

		void		drawPlayers(sf::RenderWindow& window, Engine* engine);
		void		drawMap(sf::RenderWindow& window);

		void		displayMap(sf::RenderWindow& window, Engine* engine);

		void		reactKey(Engine* gameEngine, sf::RenderWindow& window, \
								sf::Event& event, bool& game);
		void		reactMouse(Engine* gameEngine, sf::RenderWindow& window, \
								sf::Event& event, bool& game);

		void		routine(Engine& engine);
};

#endif
