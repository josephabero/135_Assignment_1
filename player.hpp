#ifndef	PLAYER_HPP
#define	PLAYER_HPP

#include "option.hpp"
#include <string>

class Player
{
  public:
  virtual void setOption(Option option) = 0;
  virtual Option getOption() = 0;
  virtual void generateOption() = 0;
  virtual int getScore()  const  = 0;
  virtual void setScore(int score) = 0;
  virtual void incrementScore() = 0;
  virtual void setUsername(std::string username) = 0;
  virtual std::string getUsername() const = 0;
};

#endif
