#include "Engine.hpp"

bool	Engine::isFreeThree(const int* line) const
{
	if (line[0] != EMPTY)
		return (false);

	if (line[1] != EMPTY && line[2] != EMPTY \
		&& line[3] != EMPTY && line[4] == EMPTY)
		return (true);

	if (line[1] != EMPTY && line[2] == EMPTY \
		&& line[3] != EMPTY && line[4] != EMPTY \
		&& line[5] == EMPTY)
		return (true);

	if (line[1] != EMPTY && line[2] != EMPTY \
		&& line[3] == EMPTY && line[4] != EMPTY \
		&& line[5] == EMPTY)
		return (true);

	return (false);
}

bool	Engine::isLineFive(void)
{
	int		value = 0;

	value = getFiveLine(_otherPlayer, _board);
	if (value == 0)
		return (false);

	vector<int>		legalMoves = {0};

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

bool	Engine::isCapturing(const int x, const int y, const int player, const int* board)
{
	int		coords[48] = { -42, 1,  -42, 2,  -42, 3,  -42, -1,  -42, -2,  -42, -3, \
							1, -42,  2, -42,  3, -42,  -1, -42, -2, -42,  -3, -42, \
							1, 1,  2, 2,  3, 3,  1, -1,  2, -2, 3, -3, \
							-1, 1,  -2, 2,  -3, 3,  -1, -1,  -2, -2,  -3, -3 };

	int		pl[6] = {0, 0, 0, 0, 0, 0};
	int		p1, p2, p3;

	for (int i = 0, j = 0; i != 48; i += 6, j = 0)
	{
		pl[0] = 0, pl[1] = 0, pl[2] = 0;
		pl[3] = 0, pl[4] = 0, pl[5] = 0;

		for (int k = 0; k != 6; k += 2)
		{
			int newX = x, newY = y;

			if (coords[i + k] != -42)
				newY = y + coords[i + k];
			if (coords[i + k + 1] != -42)
				newX = x + coords[i + k + 1];

			if (newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT)
				continue ;

			if (board[(newY * MAP_WIDTH) + newX] != 0)
				pl[j] = newX, pl[j + 1] = newY, j += 2;
		}

		p1 = getInfo(pl[0], pl[1], board);
		p2 = getInfo(pl[2], pl[3], board);
		p3 = getInfo(pl[4], pl[5], board);

		if (j == 6 && p1 != 0 && p1 == p2 && p1 != p3 && p3 == player)
			return (true);
	}

	return (false);
}

bool	Engine::isLegal(const int x, const int y, const int player)
{
	if (x < 0 || y < 0)
		return (false);

	if (x >= MAP_WIDTH || y >= MAP_HEIGHT)
		return (false);

	if (getInfo(x, y, _board) != EMPTY)
		return (false);

	if (isCapturing(x, y, player, _board) == false)
	{
		if (DOUBLE_THREE == 0 && verifyFreeThree(x, y, player) == false)
			return (false);
	}

	return (true);
}

int		Engine::isGameOver(void)
{
	if (_actualPlayer == PLAYER_1 && _p2Cptd >= CAPTURE)
		return (PLAYER_2);

	if (_actualPlayer == PLAYER_2 && _p1Cptd >= CAPTURE)
		return (PLAYER_1);

	if (isLineFive() == true)
		return (_otherPlayer);

	if (getLegalMoves(_actualPlayer).size() == 0)
		return (-1);

	return (0);
}
