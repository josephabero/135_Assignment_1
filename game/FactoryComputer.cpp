#include "FactoryComputer.hpp"

Computer *Factory::makeComputer(Mode mode)
{ 
    switch(mode)
    {
        case Mode::Dumb: 
        {
            return new DumbComputer();
            break;
        }
       
        case Mode::Smart:
        {
            return new SmartComputer();
            break;
        }
    }
}