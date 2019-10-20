#ifndef OPTION_HPP
#define OPTION_HPP

#include <iostream>
#include "wx/wx.h"
using namespace std;

enum class Option
{
    ROCK, PAPER, SCISSORS
};

inline ostream& operator << (ostream& ost, const Option option)
{
    switch(option)
    {
        case Option::ROCK:      ost << "Rock";          break;
        case Option::PAPER:     ost << "Paper";         break;
        case Option::SCISSORS:  ost << "Scissors";      break;
        default:                ost << "unspecified";   break;
    }
    return ost;
}

inline string optionString(const Option option)
{
	switch(option)
    {
        case Option::ROCK:      return "R";
        case Option::PAPER:     return "P";
        case Option::SCISSORS:  return "S";
        default:                return "U";
    }
}

wxString optionToWxString(const Option option)
{
    wxString result;
    switch(option)
    {
        case Option::ROCK:      result = "Rock";          break;
        case Option::PAPER:     result = "Paper";         break;
        case Option::SCISSORS:  result = "Scissors";      break;
        default:                result = "unspecified";   break;
    }
    return result;
}

#endif