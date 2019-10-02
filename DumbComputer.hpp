#ifndef	DUMBCOMPUTER_HPP
#define	DUMBCOMPUTER_HPP

#include "computer.hpp"

class DumbComputer : public Computer
{
    public:
    void setOption(Option option);
	void generateOption();
    Option getOption();
    private:
    Option option;
};

#endif
