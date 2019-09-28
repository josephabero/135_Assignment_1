#ifndef	GAME_HPP
#define	GAME_HPP

#include "player.hpp"
#include "user.hpp"
#include "computer.hpp"
#include "winner.hpp"

class Game
{
public:
	Game(Player & player1, Player & player2);

	void displayScore();
	void gameStart();
	void gameEnd();
	void displayOptions();
	void runGame(Player & player1, Player & player2);
	Winner evaluateUserWin(Player & player1, Player & player2);

private:
	bool activeGame;
	Player & humanPlayer;
	Player & compPlayer;
};

#endif
