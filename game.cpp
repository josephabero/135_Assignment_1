#include <iostream>
#include "game.hpp"
using namespace std;

Game::Game(Player & player1, Player & player2) : humanPlayer(player1), compPlayer(player2)
{
    activeGame = false;
}

void Game::runGame(Player & player1, Player & player2)
{
    // Step 1: Start Game
    gameStart();


    int round_count = 0;
    player1.setScore(0);
    player2.setScore(0);

    // Step 2: Display Initial Score
    displayScore();


    // Step 3: Choose User Option
    // Step 4: Choose Computer Option
    // Step 5: Evaluate the Winner
    // Step 6: Show Score

    // -- Repeat Steps 3-6 until Score threshold is met --
    do
    {
        cout << "----------------------------------" << endl;
        displayOptions();

        compPlayer.generateOption();

        cout << "Computer chose " << compPlayer.getOption() << endl;

        int winner = evaluateUserWin(player1, player2);
        switch(winner)
        {
            case 0:
                cout << "It was a TIE!" << endl;
                break;
            case 1:
                cout << "YOU Won!" << endl;
                humanPlayer.incrementScore();
                break;
            case 2:
                cout << "COMPUTER Won" << endl;
                compPlayer.incrementScore();
                break;
        }

        displayScore();
        round_count++;

    }while(round_count < 20);

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
            << "YOYO" << ": " << humanPlayer.getScore()  << endl
            << "Computer: " << compPlayer.getScore()   << endl
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

        humanPlayer.setOption(static_cast<Option>(userInput));
    }
}

int Game::evaluateUserWin(Player & player1, Player & player2)
{
    // 0 = tie, 1 = user win, 2 = comp win
    int winner = 0;
    Option compOption = compPlayer.getOption();

    if(activeGame)
    {
        if(humanPlayer.getOption() == compOption)
        {
          winner  = 0;
        }
        switch(humanPlayer.getOption())
        {
            case (Option::ROCK):
                if(compOption == Option::PAPER)         winner = 2;
                else                                    winner = 1;
                break;
            case (Option::PAPER):
                if     (compOption == Option::ROCK)     winner = 1;
                else                                    winner = 2;
                break;
            case (Option::SCISSORS):
                if     (compOption == Option::ROCK)     winner = 2;
                else                                    winner = 1;
                break;
        }
    }

    return winner;
}
