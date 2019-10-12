#ifndef FACTORYCOMPUTER_HPP
#define FACTORYCOMPUTER_HPP
#include "computer.hpp"
#include "DumbComputer.hpp"
#include <string.h>
#include "SmartComputer.hpp"

enum class mode
{
    Dumb,
    Smart
};
class Factory
{
    public:
   
    Factory(){};
    static Computer *makeComputer(mode mode);

};

#endif