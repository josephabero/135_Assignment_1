#include <stdlib.h>
#include "player.hpp"
#include "option.hpp"

class Computer: public PlayerFactory
{
public:
	Computer() : PlayerFactory("Computer", Option::ROCK, 0) 
	{}

	void setOption(Option option) { this->option = option; };
    Option getOption()			  { return option; };
	
	void generateOption()
	{
		// generate random option
		setOption(static_cast<Option>((rand() % 3)));
	}
};
