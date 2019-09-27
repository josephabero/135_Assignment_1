#include <iostream>
// #include "option.hpp"
#include "player.hpp"
using namespace std;

int Player::getScore()   const 
{
 	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}

void Player::incrementScore()
{
	score++;
}

void Player::setOption(int option)
{
 	this->option = option;
}

int Player::getOption()
{
    return option;
}