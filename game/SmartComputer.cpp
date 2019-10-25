#include "SmartComputer.hpp"
#include <map>
#include <fstream>
#include <sstream>
using namespace std;

SmartComputer::SmartComputer()
{
	option = Option::ROCK;
	num_of_prev_options = 5;
	recorded_options = readRecordsFromFile();
	recent_options = "";
}

void SmartComputer::setOption(Option option)
{
    this->option = option;
}

Option  SmartComputer::getOption()
{
    return option;
}

Option  SmartComputer::getPredicted()
{
    return predicted;
}


void SmartComputer::generateOption(Option userChoice)
{
	// 1. Take User Choice
	// 2. Update Frequency table of Prev Round's Choices
	// 3. Assess the frequency
	// 4. Choose highest frequency
	// 5. Set Computer's Option
	// 6. Write Records to File


	// 1. Store Last User Choice
	storeRecentChoice(userChoice);

	// 2. Update frequency table
	storeSequence(recent_options);

	// Stores Computer's Last Choice
	storeRecentChoice(option);

	// Reduces recent_options to size of n
	updateRecentOptions();


	// 3. Assess Frequency of Possible Choices
	string test = "RPS";
	string highestFreq = recent_options + test[0];

	// Iterate through each potential choice ('R', 'P', 'S') and assess highest frequency
	// EX. Last 4 Choices were RSPS
	//     Looks for largest frequency of 'RSPSR', 'RSPSP', RSPSS
	for(int i = 0; i < 3; i++)
	{
		// 4. Choose highest frequency
		if(recorded_options[recent_options + test[i]] > recorded_options[highestFreq]){
			highestFreq = recent_options + test[i];
		}
	}


	// Return Computer Choice
	Option compChoice;
	switch(highestFreq.back())
	{
		case 'R':	compChoice = Option::PAPER;		predicted = Option::ROCK;		break;
		case 'P':	compChoice = Option::SCISSORS;	predicted = Option::PAPER;		break;
		case 'S':	compChoice = Option::ROCK;		predicted = Option::SCISSORS;	break;
		default:	compChoice = static_cast<Option>(rand()%3);						break;
	}

	setOption(compChoice);

	printRecordsToFile();
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

void SmartComputer::printRecordsToFile()
{
	string filename = "SmartChooserRecords.csv";

	ofstream file;
	// open file and delete contents if file exists
	file.open(filename, ios::out | ios::trunc);	

	for(auto elem : recorded_options)
	{
	   file << elem.first << ":" << elem.second << "\n";
	}
	file.close();
}

map<string, int> SmartComputer::readRecordsFromFile()
{
	map<std::string, int> records;

	string filename = "SmartChooserRecords.csv";

	ifstream file;
	file.open(filename, ios::in);
	if(file.fail())
	{
		records = {
			{"RRRRR", 0}
		};
	}
	else
	{
		string line;
		string key;
		string val;
		while(getline(file, line, '\n'))
		{
			stringstream ss(line);
			getline(ss, key, ':');
			getline(ss, val, '\n');

			records[key] = stoi(val);
		}
		file.close();
	}
	return records;
}