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

inline wxString winnerToWxString(const Winner winner)
{
    wxString result;
    switch(winner)
    {
        case Winner::TIE:      	result = "Tie";         break;
        case Winner::YOU:     	result = "You";         break;
        case Winner::COMPUTER:  result = "Computer";    break;
        default:                result = "unspecified"; break;
    }
    return result;
}

#endif