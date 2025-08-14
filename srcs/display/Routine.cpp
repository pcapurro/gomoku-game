#include "Display.hpp"
#include "Engine.hpp"
#include "Ai.hpp"

void	routine(void* engine, void* ai)
{
	Engine*				gameEngine = (Engine*) engine;
	Ai*					gameAi = (Ai*) ai;

	sf::RenderWindow	window(sf::VideoMode(WINDOW_W, WINDOW_H), "gomoku-game");

	centerWindow(window);

	drawMap(window, gameEngine);
	window.display();

	while (window.isOpen() == true)
	{
		sf::Event	event;
		bool		game = true;

		while (window.pollEvent(event) == true)
		{
			if (event.type == sf::Event::Closed \
				|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::KeyPressed \
				&& event.key.code == sf::Keyboard::Enter)
			{
				gameEngine->resetGame();
				game = true;

				drawMap(window, gameEngine);
				window.display();
			}

			if (event.type == sf::Event::MouseButtonReleased \
				&& event.mouseButton.button == sf::Mouse::Left \
				&& game == true)
			{
				int	x = event.mouseButton.x / (WINDOW_W / MAP_WIDTH);
				int	y = event.mouseButton.y / (WINDOW_H / MAP_HEIGHT);

				gameEngine->playMove(x, y);

				drawMap(window, gameEngine);
				window.display();

				if (gameEngine->getGameState() != 0)
					gameEngine->printSummary(), game = false;
			}
		}
	}
}
