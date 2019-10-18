#ifndef	USER_HPP
#define	USER_HPP

#include "option.hpp"
#include "Score.hpp"
#include <string>

class User
{
public:
    
    User();	
    void setUsername(std::string username);
    std::string getUsername() const;
    void setOption(Option option);
    Option getOption();

private:
	std::string username;
    Option option;
};

#endif