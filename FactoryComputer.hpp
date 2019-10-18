#ifndef FACTORYCOMPUTER_HPP
#define FACTORYCOMPUTER_HPP
#include "computer.hpp"
#include "DumbComputer.hpp"
#include <string.h>
#include "SmartComputer.hpp"

enum class Mode
{
    Dumb,
    Smart
};

class Factory
{
    public:
   
    Factory(){};
    static Computer *makeComputer(Mode mode);

};

#endif