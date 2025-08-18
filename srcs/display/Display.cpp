#include "Display.hpp"
#include "Engine.hpp"

void	Display::centerWindow(sf::RenderWindow& window)
{
	sf::VideoMode		screen = sf::VideoMode::getDesktopMode();

	window.setPosition(sf::Vector2i((screen.width - WINDOW_W) / 2,\
		(screen.height - WINDOW_H) / 2));
}

void	Display::displayMap(sf::RenderWindow& window, Engine* engine)
{
	window.clear();

	drawMap(window, engine);
	window.display();
}

sf::Color	Display::getPlayerColor(const int player)
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

void	Display::drawMap(sf::RenderWindow& window, Engine* engine)
{
	const int*			map = engine->getMap();
	sf::RectangleShape	rectangle(sf::Vector2f(WINDOW_W / MAP_WIDTH, WINDOW_H / MAP_HEIGHT));
	sf::CircleShape		circle(std::min((WINDOW_W / MAP_WIDTH) / 2, (WINDOW_H / MAP_HEIGHT) / 2));

	rectangle.setFillColor(sf::Color::White);
	rectangle.setOutlineColor(sf::Color::Black);
	rectangle.setOutlineThickness(2.f);

	window.clear();

	int 	x = 0;
	int		y = 0;

	for (int i = 0; i != MAP_HEIGHT; i++)
	{
		x = 0;
		y = (WINDOW_H / MAP_HEIGHT) * i;

		for (int k = 0; k != MAP_WIDTH; k++)
		{
			x = (WINDOW_W / MAP_WIDTH) * k;
			rectangle.setPosition(x, y);
			window.draw(rectangle);

			if (map[i * MAP_WIDTH + k] != EMPTY)
			{
				circle.setPosition(x, y);

				if (map[i * MAP_WIDTH + k] == PLAYER_1)
					circle.setFillColor(getPlayerColor(PLAYER_1));
				else
					circle.setFillColor(getPlayerColor(PLAYER_2));

				window.draw(circle);
			}
		}
	}
}
