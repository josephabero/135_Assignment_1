#ifndef	GAME_HPP
#define	GAME_HPP
#include "computer.hpp"
#include "user.hpp"
#include "computer.hpp"
#include "winner.hpp"

class Game
{
public:

	Game(Computer * player2, User * player1);
	void displayScore();
	void gameStart();
	void gameEnd();
	void displayOptions();
	void runGame();
	Winner evaluateUserWin();

private:
	bool activeGame;
	Computer *compPlayer;
	User *humanPlayer;
	Score humanScore;
	Score computerScore;
};

#endif
