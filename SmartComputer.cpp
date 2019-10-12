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

	// updateRecentOptions(userChoice);
	cout << "GEN OPTION DEBUG" 
		<< endl << "-------------------" << endl;
	cout << "Last User    : " << userChoice << endl;
	cout << "Last Computer: " << option << endl;
	recent_options += optionString(userChoice); // store user's last round choice

	// Stores UCUCU
	cout << "Storing: " << recent_options << endl;
	recorded_options[recent_options] += 1;

	// Stores computer's last round
	recent_options += optionString(option);		// store computer's last round choice
	


	// recent_options.erase(0, 1);
	// cout << "Before LUC: " << recent_options << endl;

	if(recent_options.size() >= num_of_prev_options)
	{
		// recent_options.erase(0, 1);
		// cout << "After First char: " << recent_options << endl;
		recent_options.erase(0, recent_options.size() - num_of_prev_options + 1); 
	}

	// cout << "After LUC: " << recent_options << endl;
	// recent_options.erase(0, 1);


	string test = "RPS";
	string highestFreq = recent_options + test[0];

	// iterate through each choice and assess highest frequency
	for(int i = 0; i < 3; i++)
	{
		cout << recent_options + test[i] << ": " << recorded_options[recent_options + test[i]] << endl;
		if(recorded_options[recent_options + test[i]] > recorded_options[highestFreq]){
			highestFreq = recent_options + test[i];
		}
	}


	cout << "Highest Freq: " << highestFreq << endl;
	// recorded_options[highestFreq] += 1;
	// cout << recorded_options[highestFreq] << endl;

	Option tempOpt;


	switch(highestFreq.back())
	{
		case 'R':	tempOpt = Option::PAPER;	break;
		case 'P':	tempOpt = Option::SCISSORS;	break;
		case 'S':	tempOpt = Option::ROCK;		break;
		default:	tempOpt = Option::ROCK;		break;
	}


	// updateRecentOptions(tempOpt);
	cout << "Computer choosing: " << tempOpt << endl << endl;
	// cout << "End Gen: " << recent_options << endl;
	setOption(tempOpt);

	// cout << endl << endl;
	// for(auto elem : recorded_options)
	// {
	//    std::cout << elem.first << ": " << elem.second << "\n";
	// }
	// cout << endl << endl;
}

Option  SmartComputer::getOption()
{
    return option;
}

void SmartComputer::updateRecentOptions(Option inputOption)
{
	// Reduces to last 4 choices
	cout << "Updating: " << recent_options << endl;
	if(recent_options.size() >= num_of_prev_options)
	{
		recent_options.erase(0, recent_options.size() - num_of_prev_options + 2); 
	}

	recent_options += optionString(inputOption);
	cout << "recent_options: " << recent_options << endl;
}
