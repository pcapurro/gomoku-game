#include "Engine.hpp"

Engine::Engine(const bool optimized)
{
	_optimized = optimized;

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
		_board[i] = 0;

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
		_testBoard[i] = -1;

	_actualMove = 0;

	_state = 0;

	_actualPlayer = PLAYER_1;
	_otherPlayer = PLAYER_2;

	_p1Cptd = 0;
	_p2Cptd = 0;

	_p1CptdTest = 0;
	_p2CptdTest = 0;

	_moves = 0;

	_player1Color = NULL;
	_player2Color = NULL;

	setColors();

	_summary.clear();
}

Engine&		Engine::operator=(const Engine& original)
{
	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
		_board[i] = original._board[i];

	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
		_testBoard[i] = original._testBoard[i];

	_actualMove = original._actualMove;

	_state = original._state;

	_actualPlayer =	original._actualPlayer;
	_otherPlayer = original._otherPlayer;

	_p1Cptd = original._p1Cptd;
	_p2Cptd = original._p2Cptd;

	_p1CptdTest = original._p1CptdTest;
	_p2CptdTest = original._p2CptdTest;

	if (_optimized == false)
	{
		_moves = original._moves;

		_player1Color = original._player1Color;
		_player2Color = original._player2Color;
	}

	_summary = original._summary;

	_startTime = original._startTime;
	_endTime = original._endTime;

	return (*this);
}

void	Engine::setColors(void)
{
	if (PLAYER1_COLOR == 1)
		_player1Color = "\033[31m";
	else if (PLAYER1_COLOR == 2)
		_player1Color = "\033[32m";
	else if (PLAYER1_COLOR == 3)
		_player1Color = "\033[33m";
	else if (PLAYER1_COLOR == 4)
		_player1Color = "\033[34m";
	else if (PLAYER1_COLOR == 5)
		_player1Color = "\033[35m";
	else if (PLAYER1_COLOR == 6)
		_player1Color = "\033[36m";
	else
		_player1Color = "\033[32m";

	if (PLAYER2_COLOR == 1)
		_player2Color = "\033[31m";
	else if (PLAYER2_COLOR == 2)
		_player2Color = "\033[32m";
	else if (PLAYER2_COLOR == 3)
		_player2Color = "\033[33m";
	else if (PLAYER2_COLOR == 4)
		_player2Color = "\033[34m";
	else if (PLAYER2_COLOR == 5)
		_player2Color = "\033[35m";
	else if (PLAYER2_COLOR == 6)
		_player2Color = "\033[36m";
	else
		_player2Color = "\033[31m";
}

void	Engine::resetGame(const bool refresh)
{
	for (int i = 0; i != MAP_WIDTH * MAP_HEIGHT; i++)
		_board[i] = 0;

	if (refresh == false)
		_actualMove = 0;

	_state = 0;

	_actualPlayer = PLAYER_1;
	_otherPlayer = PLAYER_2;

	_p1Cptd = 0;
	_p2Cptd = 0;

	_p1CptdTest = 0;
	_p2CptdTest = 0;

	_moves = 0;
	_summary.clear();
}
