#include "Ai.hpp"

Ai::Ai(const bool verbose)
{
	_verbose = verbose;

	_legalMoves.clear();
	_aiPlayer = 0;
}
