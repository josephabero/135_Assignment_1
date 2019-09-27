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
    // Player(int option, int score) 
    //     : option(option), score(score)
    // {};
    
    void setUsername(std::string username);
    std::string getUsername() const;
    void setOption(Option option);
    Option getOption();
    int getScore()  const;
    void setScore(int score);
    void incrementScore();
    

private:
	std::string username;
    Option option;
    int score;
};

#endif