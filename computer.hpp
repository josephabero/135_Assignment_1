#ifndef	COMPUTER_HPP
#define	COMPUTER_HPP


#include <stdlib.h>
#include "option.hpp"
using namespace std;

class Computer
{
public:
	
	virtual void setOption(Option option) = 0;
	virtual void generateOption(Option userChoice) = 0;
	virtual Option getOption()  = 0;
	
};

#endif
