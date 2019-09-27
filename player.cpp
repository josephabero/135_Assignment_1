#include <iostream>
// #include "option.hpp"
#include "player.hpp"
using namespace std;

void Player::setUsername(string username)
{
    this->username = username;
}

string Player::getUsername() const
{
    return username;
}

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