#include "player.hpp"
using namespace std;

class Computer: public Player
{
public:
	Computer() : User("Computer", 0, 0)
	{}
	
	void generateOption()
	{
		// generate random option
		Player::setOption(rand() % 3);
	}
};