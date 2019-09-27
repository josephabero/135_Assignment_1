#include <stdlib.h>
#include "player.hpp"
#include "option.hpp"

class Computer: public Player
{
public:
	Computer() : Player("Computer", Option::ROCK, 0) 
	{}

	void setOption(Option option) { this->option = option; };
    Option getOption()			  { return option; };
	
	void generateOption()
	{
		// generate random option
		setOption(static_cast<Option>((rand() % 3)));
	}
};
