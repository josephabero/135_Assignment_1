#ifndef USER_HPP
#define USER_HPP

#include "option.hpp"
#include "player.hpp"

class User : public Player
{
public:
    User(string username, Option option, int score) : Player(username, option, score)
    {}
    
    void setOption(Option option);
    Option getOption();
};

#endif