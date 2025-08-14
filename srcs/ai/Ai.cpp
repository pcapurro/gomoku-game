#include "Ai.hpp"

int		Ai::calculate(void)
{
	int	value = 0;

	value = _legalMoves.at(rand() % _legalMoves.size()); //
	// ...

	return (value);
}

int		Ai::getBestAnswer(Engine& original)
{
	_engine = original;

	_aiPlayer = original.getActualPlayer();
	_legalMoves = original.getLegalMoves(_aiPlayer);

	auto		start = std::chrono::high_resolution_clock::now();
	int			answer = calculate();
	auto		end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double, std::milli>	total = end - start;

	cout << "AI responded with " << answer % MAP_WIDTH << " ; " << answer / MAP_WIDTH << endl;
	cout << "> Time calculation: " << std::fixed << std::setprecision(4) << total.count() << " ms" << endl;
	cout << endl;

	return (answer);
}
