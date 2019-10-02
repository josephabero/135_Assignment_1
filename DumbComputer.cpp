#include "DumbComputer.hpp"

DumbComputer::DumbComputer()
{

}
void DumbComputer::setOption(Option Option)
{
    this->option = option;
}

void DumbComputer::generateOption()
{
    setOption(static_cast<Option>(rand()%3));
}

Option DumbComputer::getOption()
{
    return option;
}