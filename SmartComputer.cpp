#include "SmartComputer.hpp"

SmartComputer::SmartComputer()
{
	num_of_prev_options = 5;
}
void SmartComputer::setOption(Option Option)
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

	updateRecentOptions(userChoice);
}

Option  SmartComputer::getOption()
{
    return option;
}

void SmartComputer::updateRecentOptions(Option userOption)
{
	// Reduces to last 4 choices
	if(recent_options.size() >= num_of_prev_options)
	{
		recent_options.erase(0, recent_options.size() - num_of_prev_options + 1); 
	}

	// add user
	recent_options += optionString(userOption);
	cout << "recent_options: " << recent_options << endl;
}