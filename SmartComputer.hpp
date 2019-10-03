#ifndef	SMARTCOMPUTER_HPP
#define	SMARTCOMPUTER_HPP

#include "computer.hpp"

class SmartComputer : public Computer
{
    public:
    SmartComputer();
    void setOption(Option option);
	void generateOption();
    Option getOption();

    private:
    Option option;
};

#endif
