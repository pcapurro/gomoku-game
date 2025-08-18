#include "Engine.hpp"

void	Engine::printSummary(void)
{
	if (_otherPlayer == PLAYER_1)
		cout << "Player " << _player1Color << "#" << _otherPlayer << END_COLOR << " won the game! 🎉" << endl;
	else
		cout << "Player " << _player2Color << "#" << _otherPlayer << END_COLOR << " won the game! 🎉" << endl;
	cout << endl;

	cout << _summary.size() << " moves were played during the game:" << endl;

	for (int i = 0; i != (int) _summary.size(); i++)
		cout << i << ". {" << _summary[i][0] << ":" << _summary[i][1] << "}  ";
	cout << endl << endl;

	cout << "Player " << _player1Color << "#1" << END_COLOR << " captured: " << _p1Cptd << endl;
	cout << "Player " << _player2Color << "#2" << END_COLOR << " captured: " << _p2Cptd << endl;
	cout << endl;

	cout << "The game lasted " << std::fixed << std::setprecision(2) \
		<< std::chrono::duration<double>(_endTime - _startTime).count() << " second(s)." << endl;
}

void	Engine::printMap(void) const
{
	cout << "\033[2J\033[H" << endl;
	cout << "Game map:" << endl << endl;

	for (int i = 0; i != MAP_HEIGHT; i++)
	{
		for (int k = 0; k != MAP_WIDTH; k++)
		{
			cout << "[";

			if (getInfo(k, i, _board) != 0)
			{
				if (getInfo(k, i, _board) == PLAYER_1)
					cout << _player1Color << 1 << END_COLOR;
				else
					cout << _player2Color << 2 << END_COLOR;
			}
			else
				cout << getInfo(k, i, _board);

			cout << "]";
		}
		cout << std::endl;
	}
	cout << endl;
}
