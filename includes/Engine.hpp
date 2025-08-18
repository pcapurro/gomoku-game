#ifndef ENGINE_HPP
# define ENGINE_HPP

# include "Gomoku.hpp"

class Engine
{
	public:
		Engine(void);
		Engine(const Engine& original) = delete;
		~Engine(void) = default;

		Engine&			operator=(const Engine& original);

		void*			playMove(const int x, const int y, const bool refresh = false);
		void			resetGame(const bool refresh = false);

		void			undoMove(void);
		void			redoMove(void);

		int				getGameState(void) const;

		const int*		getMap(void) const;
		int				getActualPlayer(void) const;
		int				getCptdValues(const int player) const;

		vector<int>		getLegalMoves(const int player);

		void			setColors(void);

		void			printSummary(void);

	private:
		void			tryMove(const int x, const int y, const int player, const bool reset = true);
		void			resetTest(void);

		void			refreshMap(void);

		void			calculateCaptures(const int x, const int y, const int player, int* board, \
											const bool simulation = false);

		void			displayMap(const int* board) const;

		bool			isLegal(const int x, const int y, const int player);
		bool			isFreeThree(const int* line) const;
		bool			isLineFive(void);

		int				isGameOver(void);

		int				getFiveLine(const int player, const int* board);
		int				getFreeThrees(const int x, const int y, const int* board, const int player) const;
		int				getAlignements(const int x, const int y, const int range, const int player, \
										const int* board) const;

		int				getInfo(const int x, const int y, const int* board) const;

		int				_board[MAP_WIDTH * MAP_HEIGHT];
		int				_testBoard[MAP_WIDTH * MAP_HEIGHT];

		int				_actualMove;

		int				_state;

		int				_actualPlayer;
		int				_otherPlayer;

		int				_p1Cptd;
		int				_p2Cptd;

		int				_p1CptdTest;
		int				_p2CptdTest;

		int				_moves;

		const char*		_player1Color;
		const char*		_player2Color;
	
		vector<vector<int>>		_summary;

		high_resolution_clock::time_point	_startTime;
		high_resolution_clock::time_point	_endTime;
};

#endif
