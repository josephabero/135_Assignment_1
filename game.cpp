#include <iostream>
#include "game.hpp"
using namespace std;

Game::Game()
{ 
	humanPlayer = new User("Player", 0, 0);
	compPlayer = new Computer();
	activeGame = false; 
}

void Game::runGame()
{
	gameStart();

	displayScore();

	do
	{
		cout << "----------------------------------" << endl;
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
	}while((compPlayer->getScore() < 10) && (humanPlayer->getScore() < 10));

	gameEnd();
}

void Game::displayScore()
{
	if(activeGame)
	{
		cout << endl << "SCORE" << endl;
		cout << "----------------------" << endl;
		cout << "User: " << humanPlayer->getScore() << endl
			<< "Computer: " << compPlayer->getScore() << endl;
			cout << "----------------------" << endl << endl;
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
	bool validInput;

	if(activeGame)
	{
		do {
			validInput = true;

			cout << "Choose an option: " << endl
				<< "1. Rock" << endl << "2. Paper" << endl
				<< "3. Scissors" << endl
				<< "Choice: ";
			cin >> userInput;
			cout << endl << endl;
	
			switch(userInput)
			{
				case 1: cout << "You chose Rock!" << endl; break;
				case 2: cout << "You chose Paper!" << endl; break;
				case 3: cout << "You chose Scissors!" << endl; break;
				default: 
					cout << "Invalid Input! Try Again!" << endl;
					validInput = false; 
					break;
			}
		} while(!validInput);
	
		humanPlayer->setOption(userInput);
	}
}

int Game::evaluateUserWin()
{
	// 0 = tie, 1 = user win, 2 = comp win
	int winner = 0;
	int compOption = compPlayer->getOption();

	if(activeGame)
	{
		switch(humanPlayer->getOption())
	    {
	        case 1: 
	            if(compOption == 1)      winner = 0; 
	            else if(compOption == 2) winner = 2;
	            else if(compOption == 3) winner = 1;
	            break;
	        case 2: 
	            if(compOption == 1)      winner = 1;            
	            else if(compOption == 2) winner = 0;
	            else if(compOption == 3) winner = 2;
	            break;
	        case 3: 
	            if(compOption == 1)      winner = 2;
	            else if(compOption == 2) winner = 1;
	            else if(compOption == 3) winner = 0;
	            break;
	    }
	}

	return winner;
}