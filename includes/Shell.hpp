#ifndef SHELL_HPP
# define SHELL_HPP

# include "Engine.hpp"

class Shell
{
	public:
		Shell(void) = default;
		Shell(const Shell& original) = delete;
		~Shell(void) = default;

		string		getParsedAnswer(const string& answer);
		int 		getPlayerAnswer(Engine& engine, string& lastMove);

		int			routine(Engine& engine);

};

#endif
