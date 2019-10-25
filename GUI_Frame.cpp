#include "GUI_Frame.hpp"
using namespace std;


const int SIDE_MARGINS = 40;

GUI_Frame::GUI_Frame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)), 
            button_panel(new ButtonPanel(this))
{
    Centre();
    
    // Init menu bar
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_ABOUT, wxT("&About"), title);
    menuFile->Append(ID_NewGame, wxT("&New Game"), "New Game");
    menuFile->Append(wxID_EXIT, wxT("&Exit"), "Exit");
    
    wxMenu *menuOption = new wxMenu;
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuOption, "&Option");
    SetMenuBar(menuBar);

    // Init sizer
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);

    // Init size
    wxSize best_size = GetBestSize();
    SetMinClientSize(best_size);

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);

    // CreateStatusBar();
    // SetStatusText("Welcome to RPS_GUI!");
    // Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
    //  wxCommandEventHandler(GUI_Frame::OnExit));
}



void GUI_Frame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void GUI_Frame::OnNewGame(wxCommandEvent& event)
{
    cout << "Starting a new game!" << endl;
    human.setScore(0);
    computer.setScore(0);
}

void GUI_Frame::OnExit(wxCommandEvent& event)
{
    cout << "Exiting RPS_GUI app!" << endl;
    Close(true);
}

GUI_Frame::~GUI_Frame()
{

}