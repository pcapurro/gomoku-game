#include "Shell.hpp"

string	Shell::getParsedAnswer(const string& answer)
{
	string	finalAnswer = "null";

	if (answer.size() < 3 || answer.size() > 7)
		return (finalAnswer);

	if (answer == "restart")
		return (answer);
	else if (answer == "end")
		return (answer);
	else
	{
		if (std::count(answer.begin(), answer.end(), ';') != 1)
			return (finalAnswer);

		for (const auto i : answer)
		{
			if (i < 48 || i > 59 || i == 58)
				return (finalAnswer);
		}

		if (answer.size() > 5)
			return (finalAnswer);

		if ((answer.size() == 3 && answer[1] != ';') \
			|| (answer.size() == 5 && answer[2] != ';'))
			return (finalAnswer);

		if (answer.size() == 3 || answer.size() == 4)
			finalAnswer = "00;00";

		if (answer.size() == 3)
			finalAnswer[1] = answer[0], finalAnswer[4] = answer[2];

		if (answer.size() == 4)
		{
			if (answer[1] == ';')
				finalAnswer[1] = answer[0], finalAnswer[3] = answer[2], finalAnswer[4] = answer[3];
			else
				finalAnswer[0] = answer[0], finalAnswer[1] = answer[1], finalAnswer[4] = answer[3];
		}

		if (answer.size() == 5)
			finalAnswer = answer;
	}

	return (finalAnswer);
}

int 	Shell::getPlayerAnswer(Engine& engine, string& lastMove)
{
	string	answer;
	int		x = 0, y = 0;

	if (engine.getPlayedMoves() != 0)
		cout << "Player " << engine.getPlayerColor(engine.getOtherPlayer()) << "#" << \
			engine.getOtherPlayer() << END_COLOR << " played " << lastMove << endl;
	cout << "> ";

	if (!getline(std::cin, answer))
		return (1);
	answer = getParsedAnswer(answer);

	if (answer == "null")
		return (-1);

	else if (answer == "restart")
		engine.resetGame();
	else if (answer == "end")
		return (1);
	else
	{
		x = atoi(answer.c_str());
		y = atoi(answer.c_str() + 3);

		if (engine.playMove(x, y) == NULL)
			return (-1);

		lastMove = std::to_string(x) + ";" + std::to_string(y);
	}

	return (0);
}
