#include "Display.hpp"
#include "Engine.hpp"

int		main(void)
{
	try
	{
		Engine		engine;
		Display		window;

		window.routine(&engine);
	}
	catch (...)
	{
		printf("An error occured.\n");
		printf("Shutting down...\n");

		return (1);
	}

	return (0);
}
