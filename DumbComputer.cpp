#include "DumbComputer.hpp"

DumbComputer::DumbComputer()
{
    option = Option::PAPER;
}
void DumbComputer::setOption(Option option)
{
    this->option = option;
}

void DumbComputer::generateOption(Option userChoice)
{
  setOption(static_cast<Option>(rand()%3));
}

Option DumbComputer::getOption()
{
    return option;
}