#include "GUI_Frame.hpp"
using namespace std;


GUI_Frame::GUI_Frame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
	Centre();
	
  	wxMenu *menuFile = new wxMenu;
  	menuFile->Append(wxID_ABOUT, wxT("&About"), title);
  	menuFile->Append(ID_NewGame, wxT("&New Game"), "New Game");
  	menuFile->Append(wxID_EXIT, wxT("&Exit"), "Exit");

  	wxMenuBar *menuBar = new wxMenuBar;
  	menuBar->Append(menuFile, "&File");
  	SetMenuBar(menuBar);

  	// CreateStatusBar();
  	// SetStatusText("Welcome to RPS_GUI!");
  	// Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
  	// 	wxCommandEventHandler(GUI_Frame::OnExit));
}



void GUI_Frame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void GUI_Frame::OnNewGame(wxCommandEvent& event)
{
	cout << "Starting a new game!" << endl;
}

void GUI_Frame::OnExit(wxCommandEvent& event)
{
	cout << "Exiting RPS_GUI app!" << endl;
	Close(true);
}

GUI_Frame::~GUI_Frame()
{

}