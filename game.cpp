#include <iostream>
#include "game.hpp"
using namespace std;

Game::Game(Computer * player2, User * player1) : compPlayer(player2)
{
    humanPlayer = player1;
    activeGame = false;
    humanScore.setScore(0);
    computerScore.setScore(0);
}

void Game::runGame()
{
    // Step 1: Start Game
    gameStart();


    int round_count = 0;
    humanScore.setScore(0);
    computerScore.setScore(0);

    // Step 2: Display Initial Score
    displayScore();


    // Step 3: Choose User Option
    // Step 4: Choose Computer Option
    // Step 5: Evaluate the Winner
    // Step 6: Show Score

    // -- Repeat Steps 3-6 until Score threshold is met --
    do
    {
        cout << "----------------------------------" << endl
            << "ROUND " << round_count + 1 << endl
            << "----------------------------------" << endl;
        displayOptions();

        compPlayer->generateOption(humanPlayer->getOption());

        cout << "Computer chose " << compPlayer->getOption() << endl;

        Winner winner = evaluateUserWin();
        switch(winner)
        {
            case Winner::TIE:
                cout << "It was a TIE!" << endl;
                break;
            case Winner::YOU:
                cout << "YOU Won!" << endl;
                humanScore.incrementScore();
                break;
            case Winner::COMPUTER:
                cout << "COMPUTER Won" << endl;
                computerScore.incrementScore();
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
            << humanPlayer->getUsername() << ": " << humanScore.getScore()  << endl
            << "Computer: " << computerScore.getScore()   << endl
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
    // 0 = tie, 1 = user win, 2 = comp win
    Winner winner;
    Option compOption = compPlayer->getOption();

    if(activeGame)
    {
        if(humanPlayer->getOption() == compOption)
        {
          winner  = Winner::TIE;
        }
        else
        {
            switch(humanPlayer->getOption())
            {
                case (Option::ROCK):
                    if(compOption == Option::PAPER)         winner = Winner::COMPUTER;
                    else                                    winner = Winner::YOU;
                    break;
                case (Option::PAPER):
                    if     (compOption == Option::ROCK)     winner = Winner::YOU;
                    else                                    winner = Winner::COMPUTER;
                    break;
                case (Option::SCISSORS):
                    if     (compOption == Option::ROCK)     winner = Winner::COMPUTER;
                    else                                    winner = Winner::YOU;
                    break;
            }
        }
    }

    return winner;
}
