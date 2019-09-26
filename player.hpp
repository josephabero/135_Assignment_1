#ifndef	PLAYER_HPP
#define	PLAYER_HPP

// #include "option.hpp"

class Player
{
public:
    Player(int option, int score) 
        : option(option), score(score)
    {};
    
    int getScore()  const;
    void setOption(int option);
    int getOption();

private:
    int option;
    int score;
};

#endif