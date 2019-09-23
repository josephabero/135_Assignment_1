// #include <iostream>
// #include "option.cpp"
// using namespace std;

// int Player::getScore()	const 
// {
// 	return score;
// }

// void Player::setOption(Option option)
// {
// 	option = option;
// }

#include "option.cpp"

class Player
{
public:
	Player(Option option, int score) 
		: option(option), score(score)
	{}
	
	int getScore()	const 			{ return score; }
	void setOption(Option option) 	{ option = option; }
	Option getOption()				{ return option; }

private:
	Option option;
	int score;
};