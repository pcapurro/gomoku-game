#include "Display.hpp"
#include "Engine.hpp"
#include "Ai.hpp"

void	routine(const void* engine, const void* ai)
{
	const Engine*		gameEngine = (Engine*) engine;
	const Ai*			gameAi = (Ai*) ai;

	sf::RenderWindow	window(sf::VideoMode(800, 750), "gomoku-game");

	while (window.isOpen() == true)
	{
		sf::Event	event;

		while (window.pollEvent(event) == true)
		{
			if (event.type == sf::Event::Closed \
				|| (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
				window.close();
		}

		window.clear();
		window.display();
	}

	(void) gameEngine;
	(void) gameAi;
}
