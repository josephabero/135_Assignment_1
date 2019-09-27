#include <iostream>
// #include "option.hpp"
#include "user.hpp"
using namespace std;

void User::setOption(Option option)
{
    this->option = option;
}

Option User::getOption()
{
    return option;
}