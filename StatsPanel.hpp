#ifndef STATS_PANEL_HPP
#define STATS_PANEL_HPP

#include "wx/wx.h"
#include "game/option.hpp"


class StatsPanel : public wxPanel
{
public:
	StatsPanel(wxFrame *parent) : wxPanel(parent, wxID_ANY)
    {
        init();
    }

private:
	wxStaticText *human_wins_text;
    wxStaticText *comp_wins_text;
    wxStaticText *ties_text;

	void init();

	void updateHumanWins(const int count);
	void updateCompWins(const int count);
	void updateTies(const int count);
};


#endif