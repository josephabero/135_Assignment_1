#include <iostream>
#include "game.hpp"
using namespace std;

void Game::displayScore()
{
	if(activeGame)
	{
		cout << endl << "SCORE" << endl;
		cout << "----------------------" << endl;
		cout << "User: " << humanPlayer.getScore() << endl
			<< "Computer: " << compPlayer.getScore() << endl;
	}
}

void Game::gameStart()
{
	activeGame = true;
}

void Game::gameEnd()
{
	activeGame = false;
}

void Game::displayOptions()
{
	int userInput;
	bool validInput = true;

	do {
		cout << "Choose an option: " << endl;
			<< "1. Rock" << endl << "2. Paper" << endl
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
	} while(!validInput)
}