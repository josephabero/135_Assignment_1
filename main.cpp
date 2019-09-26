#include <iostream>
// #include "computer.cpp"
// #include "user.hpp"
// #include "game.hpp"
  
using namespace std; 

int main() 
{ 
    // User myUser("Joseph", 0, 0);
    // Computer compUser();
    // Game newGame(false, myUser, compUser);

    int userInput = 0;
    int compInput = 0;
    bool validInput = true;
    int humanScore = 0;
    int compScore = 0;

    cout << endl << "SCORE" << endl;
    cout << "----------------------" << endl;
    cout << "User: " << humanScore << endl
        << "Computer: " << compScore << endl;

    cout << endl << "GAME START" << endl;
    cout << "----------------------" << endl;

    do {
        cout << "Choose an option: " << endl
            << "1. Rock" << endl 
            << "2. Paper" << endl
            << "3. Scissors" << endl
            << "Choice: ";
        cin >> userInput;

        switch(userInput)
        {
            case 1: cout << "You chose Rock!" << endl; break;
            case 2: cout << "You chose Paper!" << endl; break;
            case 3: cout << "You chose Scissors!" << endl; break;
            default: validInput = false; break;
        }
    } while(!validInput);

    compInput = (rand() % 2) + 1;
    cout << endl << endl;
    switch(compInput)
    {
        case 1: cout << "Computer chose Rock!" << endl; break;
        case 2: cout << "Computer chose Paper!" << endl; break;
        case 3: cout << "Computer chose Scissors!" << endl; break;
    }

    cout << "." << endl << "." << endl << "." << endl;

    switch(userInput)
    {
        case 1: 
            if(compInput == 1)      cout << "It's a Tie" << endl; 
            else if(compInput == 2) { cout << "Computer Won" << endl; compScore++; }
            else if(compInput == 3) { cout << "You Won!" << endl; humanScore++; }
            break;
        case 2: 
            if(compInput == 1)      { cout << "You Won!" << endl; humanScore++; }            
            else if(compInput == 2) cout << "It's a Tie" << endl;
            else if(compInput == 3) { cout << "Computer Won!" << endl; compScore++; }
            break;
        case 3: 
            if(compInput == 1)      { cout << "Computer Won!" << endl; compScore++; }
            else if(compInput == 2) { cout << "You Won!" << endl;  humanScore++; }
            else if(compInput == 3) cout << "It's a Tie" << endl;
            break;
    }

    cout << endl << "SCORE" << endl;
    cout << "----------------------" << endl;
    cout << "User: " << humanScore << endl
        << "Computer: " << compScore << endl;

    cout << endl << "GAME END" << endl;
} 