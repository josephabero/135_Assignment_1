#ifndef	GUI_FRAME_HPP
#define	GUI_FRAME_HPP

#include <wx/wx.h>
#include "ButtonPanel.hpp"
#include "game/Score.hpp"

class GUI_Frame : public wxFrame
{
public:
    GUI_Frame(const wxString& title);

    ~GUI_Frame();

private:
	
	Score human;
	Score computer;

	void OnAbout(wxCommandEvent& event);
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();

	ButtonPanel *button_panel;
};

enum
{
    ID_NewGame  = 2
};

#endif