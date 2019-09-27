#ifndef	PLAYER_HPP
#define	PLAYER_HPP

#include "option.hpp"
#include <string>

class Player
{
public:
	Player(std::string username, Option option, int score) 
        : username(username), option(option), score(score)
    {};

    virtual void setOption(Option option) = 0;
    virtual Option getOption() = 0;
    
    void setUsername(std::string username);
    std::string getUsername() const;
    int getScore()  const;
    void setScore(int score);
    void incrementScore();
    
protected:
    Option option;

private:
	std::string username;
    int score;
};

#endif