#ifndef	GAME_H
#define	GAME_H

#include <iostream>

class User : public Player
{
public:
    User(string username, int option, int score = 0) : username(username), Player(option, score)
    {}

    void setName(string name);
    string getName();

private:
    string username;
};

#endif