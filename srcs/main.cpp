#include "Display.hpp"
#include "Shell.hpp"

#include "Engine.hpp"

int		main(const int argc, const char** argv)
{
	try
	{
		Engine		engine;
		Display*	window = NULL;
		Shell*		shell = NULL;

		if (argc == 1 || string(argv[1]) != "--shell")
			window = new Display, window->routine(&engine);
		else
			shell = new Shell, shell->routine(engine);
	}
	catch (...)
	{
		printf("An error occured.\n");
		printf("Shutting down...\n");

		return (1);
	}

	return (0);
}
