#ifndef	COMPUTER_HPP
#define	COMPUTER_HPP

#include "player.hpp"
#include <stdlib.h>
#include "option.hpp"
using namespace std;

class Computer: public Player
{
public:

	Computer(){};

	void setOption(Option option)
	{
		this->option = option;
	}

	void generateOption()
	{
		// generate random option
		setOption(static_cast<Option>((rand() % 3)));
	}

	Option getOption()
	{
	    return option;
	}
	int getScore()   const
	{
	 	return score;
	}

	void setScore(int score)
	{
		this->score = score;
	}

	void incrementScore()
	{
		score++;
	}
	void setUsername(std::string username){}
	std::string getUsername() const {}
private:
	Option option;
	int score;
};

#endif
