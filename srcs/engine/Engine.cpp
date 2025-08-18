#include "Engine.hpp"

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

	if (_moves == 0)
		_startTime = std::chrono::high_resolution_clock::now();
	_endTime = std::chrono::high_resolution_clock::now();

	if (refresh == false && (int) _summary.size() != _actualMove)
	{
		for (int i = _actualMove, len = _summary.size(); i != len; i++)
			_summary.pop_back();
	}

	_summary.push_back({x, y});

	if (refresh == false)
		_actualMove++, _moves++;

	return (this);
}
