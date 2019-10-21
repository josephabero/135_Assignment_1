#ifndef ROUND_COUNT_HPP
#define ROUND_COUNT_HPP

#include "wx/wx.h"


class RoundCountPanel : public wxPanel
{
public:
	RoundCountPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

private:
	wxStaticText *round_text;

	void init();

	void updateRoundCount(const int count);
};


#endif