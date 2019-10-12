#include <iostream>
#include <memory>
#include "computer.hpp"
#include "user.hpp"
#include "DumbComputer.hpp"
#include "SmartComputer.hpp"
#include "game.hpp"

using namespace std;

int main()
{
    string nameInput;
    User *humanPlayer = new User();
    Computer *compPlayer =  new SmartComputer();

    Game newGame(compPlayer, humanPlayer);

    cout << "Enter your name: ";
    cin >> nameInput;
    humanPlayer->setUsername(nameInput);

    cout << "Hello " << humanPlayer->getUsername() << "!" << endl;
    newGame.runGame();
    delete compPlayer;
    return 0;
}
