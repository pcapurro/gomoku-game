#include "Engine.hpp"

int		Engine::getInfo(const int x, const int y, const int* board) const
{
	return (board[(y * MAP_WIDTH) + x]);
}

int		Engine::getGameState(void) const
{
	return (_state);
}

const int*	Engine::getMap(void) const
{
	return (_board);
}

int		Engine::getActualPlayer(void) const
{
	return (_actualPlayer);
}

int		Engine::getOtherPlayer(void) const
{
	if (_actualPlayer == PLAYER_1)
		return (PLAYER_2);

	return (PLAYER_1);
}

int		Engine::getCptdValues(const int player) const
{
	if (player == PLAYER_1)
		return (_p1Cptd);

	return (_p2Cptd);
}

int		Engine::getPlayedMoves(void) const
{
	return (_moves);
}

string		Engine::getPlayerColor(const int player)
{
	if (player == PLAYER_1)
		return (_player1Color);

	return (_player2Color);
}

vector<int>		Engine::getLegalMoves(const int player)
{
	vector<int>		legalMoves = {0};

	legalMoves.clear();

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
	{
		if (isLegal(i % MAP_WIDTH, i / MAP_WIDTH, player) == true)
			legalMoves.push_back(i);
	}

	return (legalMoves);
}

int		Engine::getFreeThrees(const int x, const int y, const int* board, const int player) const
{
	int		coords[16] = { -42, 1,  -42, -1,  1, -42,  -1, -42,  \
							1, -1,  -1, -1,  1, 1,  -1, 1 };

	int		line[6] = {0, 0, 0, 0, 0, 0};

	int		number = 0, value = 0;
	int		free = 0, elements = 0;

	for (int i = 0; i != 16; i += 2, elements = 0, free = 0)
	{
		for (int k = -1; k != 5; k++)
		{
			int		newY = y;
			int		newX = x;

			if (coords[i] != -42)
				newY = y + (k * coords[i]);
			if (coords[i + 1] != -42)
				newX = x + (k * coords[i + 1]);

			if (newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT)
				continue ;

			value = board[(newY * MAP_WIDTH) + newX];

			if (value == EMPTY || value == player)
			{
				line[elements] = value;
				elements++;

				if (value == EMPTY)
					free++;
			}
		}

		if (elements >= 5 && free <= 3 && isFreeThree(line) == true)
			number++;
	}

	return (number);
}

int		Engine::getAlignements(const int x, const int y, const int range, const int player, const int* board) const
{
	int		coords[16] = { -42, 1,  -42, -1,  1, -42,  -1, -42,  \
							1, -1,  -1, -1,  1, 1,  -1, 1 };
	int		value = 0;
	int		number = 0;

	for (int i = 0; i != 16; i += 2)
	{
		number = 0;

		for (int k = 0; k != range; k++)
		{
			int	newY = y;
			int	newX = x;

			if (coords[i] != -42)
				newY = y + (k * coords[i]);
			if (coords[i + 1] != -42)
				newX = x + (k * coords[i + 1]);

			if (newX < 0 || newX >= MAP_WIDTH || newY < 0 || newY >= MAP_HEIGHT)
				continue ;

			if (board[(newY * MAP_WIDTH) + newX] == player)
				number++;
			else
				break ;
		}

		if (number == range)
			value++;
	}

	return (value);
}

void	Engine::calculateCaptures(const int x, const int y, const int player, int* board, const bool simulation)
{
	int		coords[48] = { -42, 1,  -42, 2,  -42, 3,  -42, -1,  -42, -2,  -42, -3, \
							1, -42,  2, -42,  3, -42,  -1, -42, -2, -42,  -3, -42, \
							1, 1,  2, 2,  3, 3,  1, -1,  2, -2, 3, -3, \
							-1, 1,  -2, 2,  -3, 3,  -1, -1,  -2, -2,  -3, -3 };

	int		pl[6] = {0, 0, 0, 0, 0, 0};

	int*	p1Cptd = NULL;
	int*	p2Cptd = NULL;

	int		p1, p2, p3;

	if (simulation == false)
		p1Cptd = &_p1Cptd, p2Cptd = &_p2Cptd;
	else
		p1Cptd = &_p1CptdTest, p2Cptd = &_p2CptdTest;

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
		{
			board[(pl[1] * MAP_WIDTH) + pl[0]] = 0;
			board[(pl[3] * MAP_WIDTH) + pl[2]] = 0;

			if (player == PLAYER_1)
				*p1Cptd += 2;
			else
				*p2Cptd += 2;
		}
	}
}

int		Engine::getFiveLine(const int player, const int* board)
{
	int		value = 0;

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
	{
		if (board[i] == player \
			&& getAlignements(i % MAP_WIDTH, i / MAP_WIDTH, 5, player, board) > 0)
			value++;
	}

	return (value);
}

void	Engine::tryMove(const int x, const int y, const int player, const bool reset)
{
	if (reset == true)
		resetTest();

	_testBoard[(y * MAP_WIDTH) + x] = player;

	calculateCaptures(x, y, player, _testBoard, true);
}

void	Engine::resetTest(void)
{
	_p1CptdTest = _p1Cptd;
	_p2CptdTest = _p2Cptd;

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
		_testBoard[i] = _board[i];
}

void	Engine::refreshMap(void)
{
	vector<vector<int>>		summary;

	summary = _summary;
	resetGame(true);

	for (int i = 0; i != _actualMove; i++)
		playMove(summary[i][0], summary[i][1], true);

	_summary = summary;
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
