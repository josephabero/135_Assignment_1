#ifndef	GUI_FRAME_HPP
#define	GUI_FRAME_HPP

#include <wx/wx.h>

class GUI_Frame : public wxFrame
{
public:
    GUI_Frame(const wxString& title);

private:
	void OnAbout(wxCommandEvent& event);
	void OnNewGame(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();

	~GUI_Frame();
};

enum
{
    ID_NewGame  = 2
};

#endif