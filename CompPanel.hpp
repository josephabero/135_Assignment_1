#ifndef COMP_PANEL_HPP
#define COMP_PANEL_HPP

#include "wx/wx.h"
#include "game/option.hpp"


class CompPanel : public wxPanel
{
public:
	CompPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

private:
    wxStaticText *predicted_text;
    wxStaticText *choice_text;

	void init();

	void updatePredictText(const Option option);
	void updateChoiceText(const Option option);
};


#endif