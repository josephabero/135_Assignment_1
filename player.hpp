#ifndef	PLAYER_HPP
#define	PLAYER_HPP

#include "option.hpp"
#include <string>

class Player
{
  public:
  virtual void setOption(Option option) = 0;
  virtual Option getOption() = 0;
};

#endif
