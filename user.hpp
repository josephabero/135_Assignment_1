#ifndef	USER_HPP
#define	USER_HPP

#include "player.hpp"
#include "option.hpp"
#include <string>

class User : public Player
{
public:
    
    User();
		
    void setUsername(std::string username);
    std::string getUsername() const;
    void setOption(Option option);
    Option getOption();
	void generateOption();
    int getScore()  const;
    void setScore(int score);
    void incrementScore();


private:
	std::string username;
    Option option;
    int score;
};

#endif
