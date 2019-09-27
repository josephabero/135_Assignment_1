#include "player.hpp"
#include <stdlib.h>
#include "option.hpp"
using namespace std;

class Computer: public Player
{
public:
	Computer() : Player("Computer", Option::ROCK, 0) 
	{}
	
	void generateOption()
	{
		// generate random option
		Player::setOption(static_cast<Option>((rand() % 3)));
	}
};