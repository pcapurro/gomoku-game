#include "Engine.hpp"

int		Engine::isGameOver(void)
{
	if (_actualPlayer == PLAYER_1 && _p2Cptd >= 10)
		return (PLAYER_2);

	if (_actualPlayer == PLAYER_2 && _p1Cptd >= 10)
		return (PLAYER_1);

	if (isLineFive() == true)
		return (_otherPlayer);

	if (getLegalMoves(_actualPlayer).size() == 0)
		return (-1);

	return (0);
}

bool	Engine::isLegal(const int x, const int y, const int player)
{
	if (x < 0 || y < 0)
		return (false);

	if (x >= MAP_WIDTH || y >= MAP_HEIGHT)
		return (false);

	if (getInfo(x, y, _board) != EMPTY)
		return (false);

	int		alignNow = 0;
	int		alignAfter = 0;

	tryMove(x, y, player);

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
	{
		if (_board[i] == player)
			alignNow += getFreeThrees(i % MAP_WIDTH, i / MAP_WIDTH, _board, player);
		if (_testBoard[i] == player)
			alignAfter += getFreeThrees(i % MAP_WIDTH, i / MAP_WIDTH, _testBoard, player);
	}

	if ((alignAfter / 2) - (alignNow / 2) == 2)
		return (false);

	return (true);
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

	if (_moves == 0)
		_startTime = std::chrono::high_resolution_clock::now();

	if (_state != 0)
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
