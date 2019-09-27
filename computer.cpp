#include "player.hpp"
#include <stdlib.h>
using namespace std;

class Computer: public Player
{
public:
	Computer() : Player("Computer", 0, 0) 
	{}
	
	void generateOption()
	{
		// generate random option
		Player::setOption((rand() % 3) + 1);
	}
};