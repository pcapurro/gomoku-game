#include "Display.hpp"
#include "Engine.hpp"
#include "Ai.hpp"

int		main(void)
{
	try
	{
		Engine	engine(false);
		Ai*		ai = NULL;

		if (GAME_MODE == PVE)
			ai = new Ai;

		routine(&engine, ai);
	}
	catch (...)
	{
		printf("An error occured.\n");
		printf("Shutting down...\n");

		return (1);
	}

	return (0);
}
