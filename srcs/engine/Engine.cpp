#include "Engine.hpp"

void	Engine::displayMap(const int* board) const
{
	for (int i = 0; i != MAP_HEIGHT; i++)
	{
		for (int k = 0; k != MAP_WIDTH; k++)
		{
			std::cout << "[";

			if (getInfo(k, i, board) != 0)
			{
				if (getInfo(k, i, board) == PLAYER_1)
					std::cout << _player1Color << 1 << END_COLOR;
				else
					std::cout << _player2Color << 2 << END_COLOR;
			}
			else
				std::cout << getInfo(k, i, board);

			std::cout << "]";
		}
		std::cout << std::endl;
	}
}

void	Engine::undoMove(void)
{
	if (_actualMove != 0)
		_actualMove--, refreshMap();
}

void	Engine::redoMove(void)
{
	if (_actualMove != (int) _summary.size())
		_actualMove++, refreshMap();
}

void*	Engine::playMove(const int x, const int y, const bool refresh)
{
	if (isLegal(x, y, _actualPlayer) == false)
		return (NULL);

	_board[(y * MAP_WIDTH) + x] = _actualPlayer;

	calculateCaptures(x, y, _actualPlayer, _board);

	if (_actualPlayer == PLAYER_1)
		_actualPlayer = PLAYER_2, _otherPlayer = PLAYER_1;
	else
		_actualPlayer = PLAYER_1, _otherPlayer = PLAYER_2;

	_state = isGameOver();

	if (_optimized == false)
	{
		if (_moves == 0)
			_startTime = std::chrono::high_resolution_clock::now();

		_moves++;

		if (_state != 0)
			_endTime = std::chrono::high_resolution_clock::now();
	}

	if (refresh == false && (int) _summary.size() != _actualMove)
	{
		for (int i = _actualMove, len = _summary.size(); i != len; i++)
			_summary.pop_back();
	}

	_summary.push_back({x, y});
	if (refresh == false)
		_actualMove++;

	return (this);
}
