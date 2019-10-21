#ifndef	GUI_FRAME_HPP
#define	GUI_FRAME_HPP

#include <wx/wx.h>
#include "ButtonPanel.hpp"
#include "StatsPanel.hpp"
#include "CompPanel.hpp"
#include "RoundCount.hpp"

class GUI_Frame : public wxFrame
{
public:
    GUI_Frame(const wxString& title);

    ~GUI_Frame();

private:
	void OnAbout(wxCommandEvent& event);
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();

	ButtonPanel *button_panel;
	StatsPanel *stats_panel;
	CompPanel *comp_panel;
	RoundCountPanel *round_count_panel;
};

enum
{
    ID_NewGame  = 2
};

#endif