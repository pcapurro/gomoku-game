#include "Display.hpp"
#include "Engine.hpp"

void	Display::reactMouse(Engine* gameEngine, sf::RenderWindow& window, sf::Event& event, bool& game)
{
	if (game == true)
	{
		int	x = event.mouseButton.x / (WINDOW_W / MAP_WIDTH);
		int	y = event.mouseButton.y / (WINDOW_H / MAP_HEIGHT);

		if (gameEngine->playMove(x, y) == NULL)
			cout << "Illegal move." << endl;

		displayMap(window, gameEngine);

		if (gameEngine->getGameState() != 0)
			gameEngine->printSummary(), game = false;
	}
	else
		cout << endl << "Game is over. Press ENTER to start a new game." << endl;
}

void	Display::reactKey(Engine* gameEngine, sf::RenderWindow& window, sf::Event& event, bool& game)
{
	if (event.key.code == sf::Keyboard::Enter)
	{
		gameEngine->resetGame();
		game = true;

		displayMap(window, gameEngine);
	}

	if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
	{
		if (event.key.code == sf::Keyboard::Left)
			gameEngine->undoMove();
		if (event.key.code == sf::Keyboard::Right)
			gameEngine->redoMove();

		displayMap(window, gameEngine);
	}
}

void	Display::routine(Engine& engine)
{
	sf::RenderWindow	window(sf::VideoMode(WINDOW_W, WINDOW_H), "gomoku-game");

	centerWindow(window);
	displayMap(window, &engine);

	bool	game = true;

	while (window.isOpen() == true)
	{
		sf::Event	event;

		while (window.pollEvent(event) == true)
		{
			if (event.type == sf::Event::Closed \
				|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::KeyPressed)
				reactKey(&engine, window, event, game);

			if (event.type == sf::Event::MouseButtonReleased \
				&& event.mouseButton.button == sf::Mouse::Left)
				reactMouse(&engine, window, event, game);
		}
	}
}
