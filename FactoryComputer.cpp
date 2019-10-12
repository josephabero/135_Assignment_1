#include "FactoryComputer.hpp"

Computer *Factory::makeComputer(mode mode)
    { 
           switch(mode)
           {
               case mode::Dumb: 
               {
                return new DumbComputer();
                break;
               }
               
               case mode::Smart:
               {
                return new SmartComputer();
                break;
               }
               
           }
    }