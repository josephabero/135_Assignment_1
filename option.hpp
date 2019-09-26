#ifndef	OPTION_HPP
#define	OPTION_HPP

#include <iostream>
using namespace std;

enum class Option
{
	ROCK, PAPER, SCISSORS
};

inline ostream& operator << (ostream& ost, const Option option)
{
	switch(option)
	{
		case Option::ROCK:		ost << "Rock"; 			break;
		case Option::PAPER:		ost << "Paper"; 		break;
		case Option::SCISSORS:	ost << "Scissors";		break;
		default:				ost << "unspecified"; 	break;
	}
	return ost;
}

#endif