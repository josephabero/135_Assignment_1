#ifndef	GAME_HPP
#define	GAME_HPP

#include "user.hpp"
#include "computer.cpp"

class Game
{
public:
	Game();

	void displayScore();
	void gameStart();
	void gameEnd();
	void displayOptions();
	void runGame();
	int evaluateUserWin();

private:
	bool activeGame;
	Player *humanPlayer;
	Computer *compPlayer;
};

#endif