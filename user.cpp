#include <iostream>
// #include "option.hpp"
#include "user.hpp"
using namespace std;

User::User()
{
    username = "Player";
    option = Option::ROCK;
}
void User::setUsername(string username)
{
    this->username = username;
}

string User::getUsername() const
{
    return username;
}

void User::setOption(Option option)
{
 	this->option = option;
}

Option User::getOption()
{
    return option;
}
