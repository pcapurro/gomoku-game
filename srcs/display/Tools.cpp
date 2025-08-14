#include "Display.hpp"

void	centerWindow(sf::RenderWindow& window)
{
	sf::VideoMode		screen = sf::VideoMode::getDesktopMode();

	window.setPosition(sf::Vector2i((screen.width - WINDOW_W) / 2,\
		(screen.height - WINDOW_H) / 2));
}
