#include "SmartComputer.hpp"
#include <map>
using namespace std;

SmartComputer::SmartComputer()
{
	option = Option::ROCK;
	num_of_prev_options = 5;
	recorded_options = {
		{"RRRRR", 0}
	};
	recent_options = "";
}
void SmartComputer::setOption(Option option)
{
    this->option = option;
}

void SmartComputer::generateOption(Option userChoice)
{
   //Enter ML code here
	// 1. Take User Choice
	// 2. Assess the frequency
	// 3. Choose highest frequency
	// 4. Update Frequency table
	// 5. Return


	// 1. Store Last User Choice
	cout << "GEN OPTION DEBUG" 
		<< endl << "-------------------" << endl;
	cout << "Last User    : " << userChoice << endl;
	cout << "Last Computer: " << option << endl;
	// recent_options += optionString(userChoice); // store user's last round choice
	storeRecentChoice(userChoice);
	// Stores UCUCU
	cout << "Storing: " << recent_options << endl;
	storeSequence(recent_options);

	// Stores Computer's Last Choice
	storeRecentChoice(option);


	// recent_options.erase(0, 1);
	// cout << "Before LUC: " << recent_options << endl;

	// Reduces recent_options to size of n
	updateRecentOptions();
	// if(recent_options.size() >= num_of_prev_options)
	// {
	// 	recent_options.erase(0, recent_options.size() - num_of_prev_options + 1); 
	// }

	// cout << "After LUC: " << recent_options << endl;
	// recent_options.erase(0, 1);


	string test = "RPS";
	string highestFreq = recent_options + test[0];

	// 
	// Iterate through each potential choice ('R', 'P', 'S') and assess highest frequency
	for(int i = 0; i < 3; i++)
	{
		cout << recent_options + test[i] << ": " << recorded_options[recent_options + test[i]] << endl;
		if(recorded_options[recent_options + test[i]] > recorded_options[highestFreq]){
			highestFreq = recent_options + test[i];
		}
	}


	cout << "Highest Freq: " << highestFreq << endl;

	Option compChoice;
	switch(highestFreq.back())
	{
		case 'R':	compChoice = Option::PAPER;		break;
		case 'P':	compChoice = Option::SCISSORS;	break;
		case 'S':	compChoice = Option::ROCK;		break;
		default:	compChoice = Option::ROCK;		break;
	}


	cout << "Computer choosing: " << compChoice << endl << endl;
	setOption(compChoice);

	printRecordedOptions();
}

Option  SmartComputer::getOption()
{
    return option;
}

void SmartComputer::updateRecentOptions()
{
	// Reduces to last 4 choices
	if(recent_options.size() >= num_of_prev_options)
	{
		recent_options.erase(0, recent_options.size() - num_of_prev_options + 1); 
	}

}

void SmartComputer::storeRecentChoice(Option option)
{
	recent_options += optionString(option);
}

void SmartComputer::storeSequence(string sequence)
{
	recorded_options[sequence] += 1;
}

void SmartComputer::printRecordedOptions()
{
	cout << endl << endl;
	for(auto elem : recorded_options)
	{
	   std::cout << elem.first << ": " << elem.second << "\n";
	}
	cout << endl << endl;
}