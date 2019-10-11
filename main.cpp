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
    mode modes;
    User humanPlayer;
    if (argc > 1)
    {
        if (std::string(argv[1]) == "-r")
        {
            modes = mode::Dumb;
        }

        else if (std::string(argv[1]) == "-m")
        {
           modes = mode::Smart;
        }
        else
        {
            cout << "Default to Random" << endl;
            modes = mode::Dumb;
        }  
    }
   Computer *compPlayer =  Factory::makeComputer(modes);
    //printf("here\n");
   compPlayer -> getOption();
  // std::unique_ptr<Computer> compPlayer(new DumbComputer);
    Game newGame(compPlayer, humanPlayer);

    cout << "Enter your name: ";
    cin >> nameInput;
    humanPlayer.setUsername(nameInput);

    cout << "Hello " << humanPlayer.getUsername() << "!" << endl;
    newGame.runGame();
    delete compPlayer;
    return 0;
}
