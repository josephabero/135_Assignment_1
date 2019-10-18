#ifndef WINNER_HPP
#define WINNER_HPP

#include <iostream>
using namespace std;

enum class Winner
{
    TIE, YOU, COMPUTER
};

inline ostream& operator << (ostream& ost, const Winner winner)
{
    switch(winner)
    {
        case Winner::TIE:      	ost << "TIE";         	break;
        case Winner::YOU:     	ost << "YOU";         	break;
        case Winner::COMPUTER:  ost << "COMPUTER";      break;
        default:                ost << "unspecified";   break;
    }
    return ost;
}

#endif