#ifndef BUTTONDEMO_HPP
#define BUTTONDEMO_HPP

#include "wx/wx.h"
#include "RPS_GUI.hpp"
#include "game/option.hpp"


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

private:
	wxStaticText *button_chosen_text;

	void init();
	void updateButtonOption(const Option option);
};


#endif