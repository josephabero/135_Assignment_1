#include <iostream>
// #include "option.hpp"
#include "user.hpp"
using namespace std;

User::User()
{

}
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
    int i = 0;
}

void User::setOption(Option option)
{
 	this->option = option;
}

Option User::getOption()
{
    return option;
}
