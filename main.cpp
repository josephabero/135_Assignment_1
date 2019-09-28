#include <iostream>
 #include "computer.hpp"
 #include "user.hpp"
#include "game.hpp"
#include "player.hpp"

using namespace std;

int main()
{
    string nameInput;
    User humanPlayer;
    Computer compPlayer;

    Game newGame(humanPlayer, compPlayer);

    cout << "Enter your name: ";
    cin >> nameInput;
    humanPlayer.setUsername(nameInput);

    cout << "Hello " << humanPlayer.getUsername() << "!" << endl;
    newGame.runGame(humanPlayer, compPlayer);

    return 0;
}
