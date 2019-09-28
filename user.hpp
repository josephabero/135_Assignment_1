#ifndef USER_HPP
#define USER_HPP

#include "option.hpp"
#include "player.hpp"

class User : public PlayerFactory
{
public:
    User(string username, Option option, int score) : PlayerFactory(username, option, score)
    {}

    void setOption(Option option);
    Option getOption();
};

#endif