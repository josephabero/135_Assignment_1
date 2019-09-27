#include <iostream>
#include "game.hpp"
using namespace std;

Game::Game()
{ 
    humanPlayer = new Player("Player1", Option::ROCK, 0);
    compPlayer = new Computer();
    activeGame = false; 
}

void Game::runGame()
{
    // Step 1: Start Game
    gameStart();

    string nameInput;
    cout << "Enter your name: ";
    cin >> nameInput;
    humanPlayer->setUsername(nameInput);

    cout << "Hello " << humanPlayer->getUsername() << "!" << endl;

    // Step 2: Display Initial Score
    displayScore();


    // Step 3: Choose User Option
    // Step 4: Choose Computer Option
    // Step 5: Evaluate the Winner
    // Step 6: Show Score

    // -- Repeat Steps 3-6 until Score threshold is met --
    int roundCount = 0;
    do
    {
        cout << "----------------------------------" << endl
            << "ROUND: " << roundCount + 1 << endl
            << "----------------------------------" << endl;
        displayOptions();
    
        compPlayer->generateOption();
    
        cout << "Computer chose " << compPlayer->getOption() << endl;
    
        int winner = evaluateUserWin();
        switch(winner)
        {
            case 0: 
                cout << "It was a TIE!" << endl; 
                break;
            case 1:
                cout << "YOU Won!" << endl;
                humanPlayer->incrementScore();
                break;
            case 2:
                cout << "COMPUTER Won" << endl;
                compPlayer->incrementScore();
                break;
        }
    
        displayScore();
        roundCount++;
    }while(roundCount < 20);

    // Step 7: End Game
    gameEnd();
}

void Game::displayScore()
{
    if(activeGame)
    {
        cout << endl 
            << "SCORE"                                  << endl
            << "----------------------"                 << endl
            << humanPlayer->getUsername() << ": " << humanPlayer->getScore()  << endl
            << "Computer: " << compPlayer->getScore()   << endl
            << "----------------------"                 << endl;
    }
}

void Game::gameStart()
{
    cout << "GAME START" << endl;
    activeGame = true;
}

void Game::gameEnd()
{
    cout << "GAME END" << endl << endl
        << "FINAL";;
    displayScore();
    activeGame = false;
}

void Game::displayOptions()
{
    int userInput;
    bool validInput;

    if(activeGame)
    {
        do {
            validInput = true;

            cout << "Choose an option: " << endl
                << "1. Rock"        << endl 
                << "2. Paper"       << endl
                << "3. Scissors"    << endl
                << "Choice (1-3): ";
            cin >> userInput;
            userInput--;
            cout << endl << endl;
    
            switch(static_cast<Option>(userInput))
            {
                case Option::ROCK:      cout << "You chose " << Option::ROCK     << endl; break;
                case Option::PAPER:     cout << "You chose " << Option::PAPER    << endl; break;
                case Option::SCISSORS:  cout << "You chose " << Option::SCISSORS << endl; break;
                default: 
                    cout << "Invalid Input! Try Again!" << endl;
                    validInput = false; 
                    break;
            }
        } while(!validInput);
    
        humanPlayer->setOption(static_cast<Option>(userInput));
    }
}

int Game::evaluateUserWin()
{
    // 0 = tie, 1 = user win, 2 = comp win
    int winner = 0;
    Option compOption = compPlayer->getOption();

    if(activeGame)
    {
        switch(humanPlayer->getOption())
        {
            case (Option::ROCK): 
                if     (compOption == Option::ROCK)     winner = 0; 
                else if(compOption == Option::PAPER)    winner = 2;
                else if(compOption == Option::SCISSORS) winner = 1;
                break;
            case (Option::PAPER): 
                if     (compOption == Option::ROCK)     winner = 1;            
                else if(compOption == Option::PAPER)    winner = 0;
                else if(compOption == Option::SCISSORS) winner = 2;
                break;
            case (Option::SCISSORS): 
                if     (compOption == Option::ROCK)     winner = 2;
                else if(compOption == Option::PAPER)    winner = 1;
                else if(compOption == Option::SCISSORS) winner = 0;
                break;
        }
    }

    return winner;
}