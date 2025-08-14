#include "Engine.hpp"

bool	Engine::isLegal(const int x, const int y, const int player)
{
	if (x < 0 || y < 0)
		return (false);

	if (x >= MAP_WIDTH || y >= MAP_HEIGHT)
		return (false);

	if (getInfo(x, y, _board) != 0)
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

bool	Engine::isFreeThree(const int* line) const
{
	if (line[0] != 0)
		return (false);

	if (line[1] != 0 && line[2] != 0 \
		&& line[3] != 0 && line[4] == 0)
		return (true);

	if (line[1] != 0 && line[2] == 0 \
		&& line[3] != 0 && line[4] != 0 \
		&& line[5] == 0)
		return (true);

	if (line[1] != 0 && line[2] != 0 \
		&& line[3] == 0 && line[4] != 0 \
		&& line[5] == 0)
		return (true);

	return (false);
}

bool	Engine::isLineFive(void)
{
	int		value = 0;

	value = getFiveLine(_otherPlayer, _board);
	if (value == 0)
		return (false);

	std::vector<int>	legalMoves = {0};

	legalMoves = getLegalMoves(_actualPlayer);

	for (int i = 0; i != (int) legalMoves.size(); i++)
	{
		int x = legalMoves.at(i) % MAP_WIDTH;
		int y = legalMoves.at(i) / MAP_WIDTH;

		tryMove(x, y, _actualPlayer);

		value = getFiveLine(_otherPlayer, _testBoard);
		if (value == 0)
			return (false);
	}

	return (true);
}

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
