#ifndef AI_HPP
# define AI_HPP

# include "Engine.hpp"

class Ai
{
	public:
		Ai(const bool verbose = false);
		~Ai(void) = default;

		Ai(const Ai& original) = delete;

		int					getBestAnswer(Engine& original);
		int					calculate(void);

	private:
		Engine				_engine;

		int					_aiPlayer;
		std::vector<int>	_legalMoves;

		bool				_verbose;
};

#endif
