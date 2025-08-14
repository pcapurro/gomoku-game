#include "Display.hpp"

sf::Color	getPlayerColor(const int player)
{
	if (player == PLAYER_1)
	{
		if (PLAYER1_COLOR == 1)
			return (sf::Color::Red);
		if (PLAYER1_COLOR == 2)
			return (sf::Color::Green);
		if (PLAYER1_COLOR == 3)
			return (sf::Color::Yellow);
		if (PLAYER1_COLOR == 4)
			return (sf::Color::Blue);
		if (PLAYER1_COLOR == 5)
			return (sf::Color::Magenta);
		if (PLAYER1_COLOR == 6)
			return (sf::Color::Cyan);
		else
			return (sf::Color::Green);
	}

	if (player == PLAYER_2)
	{
		if (PLAYER2_COLOR == 1)
			return (sf::Color::Red);
		if (PLAYER2_COLOR == 2)
			return (sf::Color::Green);
		if (PLAYER2_COLOR == 3)
			return (sf::Color::Yellow);
		if (PLAYER2_COLOR == 4)
			return (sf::Color::Blue);
		if (PLAYER2_COLOR == 5)
			return (sf::Color::Magenta);
		if (PLAYER2_COLOR == 6)
			return (sf::Color::Cyan);
		else
			return (sf::Color::Red);
	}

	return (sf::Color::Green);
}

void	centerWindow(sf::RenderWindow& window)
{
	sf::VideoMode		screen = sf::VideoMode::getDesktopMode();

	window.setPosition(sf::Vector2i((screen.width - WINDOW_W) / 2,\
		(screen.height - WINDOW_H) / 2));
}
