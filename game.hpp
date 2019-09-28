#ifndef	GAME_HPP
#define	GAME_HPP

#include "user.hpp"
#include "computer.cpp"
#include "winner.hpp"

class Game
{
public:
	Game();

	void displayScore();
	void gameStart();
	void gameEnd();
	void displayOptions();
	void runGame();
	Winner evaluateUserWin();

private:
	bool activeGame;
	PlayerFactory *humanPlayer;
	Computer *compPlayer;
};

#endif