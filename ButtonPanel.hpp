#ifndef BUTTONDEMO_HPP
#define BUTTONDEMO_HPP

#include "wx/wx.h"
#include "RPS_GUI.hpp"
#include "game/option.hpp"
#include "game/DumbComputer.hpp"
#include "game/SmartComputer.hpp"
#include "game/game.hpp"


class ButtonPanel : public wxPanel
{
public:

	ButtonPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }



    void onRock(wxCommandEvent& event);
    void onPaper(wxCommandEvent& event);
    void onScissors(wxCommandEvent& event);
    void ZeroScore();

private:
    wxStaticText *round_number_text;
	wxStaticText *button_chosen_text;
    wxStaticText *predicted_text;
    wxStaticText *computer_chosen_text;
    wxStaticText *winner_winner_text;
    wxStaticText *human_wins_text;
    wxStaticText *computer_wins_text;
    wxStaticText *current_ties_text;


    int round_number;
    DumbComputer Dcomp;
    SmartComputer Scomp;
    Game game;
    Score Human;
    Score Computer;
    Score Tie;

	void init();
	void updateButtonOption(const Option option);
};


#endif