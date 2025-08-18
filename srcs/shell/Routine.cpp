#include "Shell.hpp"

int		Shell::routine(Engine& engine)
{
	string		lastMove;
	int			value = 0;

	while (true)
	{
		engine.printMap();

		if (engine.getGameState() != 0)
			{ engine.printSummary(); break ; }

		value = getPlayerAnswer(engine, lastMove);

		if (value == -1)
			continue ;
		if (value == 1)
			break ;
	}

	engine.printSummary();

	return (0);
}
