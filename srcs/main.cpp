#include "Display.hpp"
#include "Shell.hpp"

#include "Engine.hpp"

int		main(const int argc, const char** argv)
{
	try
	{
		Engine		engine;

		if (argc == 1 || string(argv[1]) != "--shell")
		{
			Display		display;

			display.routine(engine);
		}
		else
		{
			Shell	shell;

			shell.routine(engine);
		}
	}
	catch (...)
	{
		fprintf(stderr, ERROR_1);
		fprintf(stderr, ERROR_2);

		return (1);
	}

	return (0);
}
