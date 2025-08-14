#include "Display.hpp"
#include "Engine.hpp"

void	drawMap(sf::RenderWindow& window, Engine* engine)
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

	(void) map;
}
