#ifndef	SMARTCOMPUTER_HPP
#define	SMARTCOMPUTER_HPP

#include "computer.hpp"
#include "option.hpp"
#include <map>
#include <queue>

class SmartComputer : public Computer
{
public:
    SmartComputer();
    void setOption(Option option);
	void generateOption(Option userChoice);
    Option getOption();

    void setNumOfPrevOptions(int num);

private:
	// Internal Functions
    void updateRecentOptions(Option userOption);

    Option option;
    int num_of_prev_options;
    map <std::string, int> recorded_options;
    
    std::string recent_options;
};

#endif
