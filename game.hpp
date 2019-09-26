#ifndef	GAME_HPP
#define	GAME_HPP

class Game
{
public:
	Game(bool activeGame, User humanPlayer, Computer compPlayer) 
		: activeGame(activeGame), humanPlayer(humanPlayer), compPlayer(compPlayer)
	{}

	void displayScore();
	void gameStart();
	void gameEnd();
	void displayOptions();
private:
	bool activeGame;
	User humanPlayer;
	Computer compPlayer;
};

#endif