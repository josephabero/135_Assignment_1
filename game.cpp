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
    // Step 1: Start Game & Request Username
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
    
        Winner winner = evaluateUserWin();
        switch(winner)
        {
            case Winner::TIE:   cout << "It was a TIE!" << endl;    break;
            case Winner::YOU:
                cout << "YOU Won!" << endl;
                humanPlayer->incrementScore();
                break;
            case Winner::COMPUTER:
                cout << "COMPUTER Won." << endl;
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

Winner Game::evaluateUserWin()
{
    Winner winner;
    Option compOption = compPlayer->getOption();

    if(activeGame)
    {
        switch(humanPlayer->getOption())
        {
            case (Option::ROCK): 
                if     (compOption == Option::ROCK)     winner = Winner::TIE; 
                else if(compOption == Option::PAPER)    winner = Winner::COMPUTER;
                else if(compOption == Option::SCISSORS) winner = Winner::YOU;
                break;
            case (Option::PAPER): 
                if     (compOption == Option::ROCK)     winner = Winner::YOU;            
                else if(compOption == Option::PAPER)    winner = Winner::TIE;
                else if(compOption == Option::SCISSORS) winner = Winner::COMPUTER;
                break;
            case (Option::SCISSORS): 
                if     (compOption == Option::ROCK)     winner = Winner::COMPUTER;
                else if(compOption == Option::PAPER)    winner = Winner::YOU;
                else if(compOption == Option::SCISSORS) winner = Winner::TIE;
                break;
        }
    }

    return winner;
}