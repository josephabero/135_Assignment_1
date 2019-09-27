#include <iostream>
// #include "computer.cpp"
// #include "user.hpp"
#include "game.hpp"
  
using namespace std; 

int main() 
{ 
    Game *newGame = new Game();

    newGame->runGame();

    return 0;
} 