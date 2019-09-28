#include <iostream>
// #include "option.hpp"
#include "user.hpp"
using namespace std;

void User::setUsername(string username)
{
    this->username = username;
}

string User::getUsername() const
{
    return username;
}

int User::getScore()   const
{
 	return score;
}

void User::setScore(int score)
{
	this->score = score;
}

void User::incrementScore()
{
	score++;
}
void User::generateOption()
{
  break;
}

void User::setOption(Option option)
{
 	this->option = option;
}

Option User::getOption()
{
    return option;
}
