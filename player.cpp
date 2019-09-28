#include <iostream>
// #include "option.hpp"
#include "player.hpp"
using namespace std;

void PlayerFactory::setUsername(string username)
{
    this->username = username;
}

string PlayerFactory::getUsername() const
{
    return username;
}

int PlayerFactory::getScore()   const 
{
 	return score;
}

void PlayerFactory::setScore(int score)
{
	this->score = score;
}

void PlayerFactory::incrementScore()
{
	score++;
}