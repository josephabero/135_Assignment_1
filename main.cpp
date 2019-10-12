#include <iostream>
#include <memory>
#include "computer.hpp"
#include "user.hpp"
#include "DumbComputer.hpp"
#include "SmartComputer.hpp"
#include "FactoryComputer.hpp"
#include "game.hpp"

using namespace std;

int main(int argc,char* argv[])
{
    string nameInput;
    User *humanPlayer = new User();
    Mode modes;

    if (argc > 1)
    {
        if (std::string(argv[1]) == "-r")
        {
            cout << "You're playing against a Dumb Computer!" << endl;
            modes = Mode::Dumb;
        }

        else if (std::string(argv[1]) == "-m")
        {
            cout << "You're playing against a Smart Computer!" << endl;
            modes = Mode::Smart;
        }
    }
    else
    {
        cout << "You're playing against a Dumb Computer!" << endl;
        modes = Mode::Dumb;
    }  

    Computer *compPlayer =  Factory::makeComputer(modes);

    Game newGame(compPlayer, humanPlayer);

    cout << "Enter your name: ";
    cin >> nameInput;
    humanPlayer->setUsername(nameInput);

    cout << "Hello " << humanPlayer->getUsername() << "!" << endl;
    newGame.runGame();

    delete humanPlayer;
    delete compPlayer;
    return 0;
}
