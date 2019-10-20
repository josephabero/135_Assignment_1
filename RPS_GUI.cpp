// #include <iostream>
// #include <wx/wx.h>

// using namespace std;

// class HelloWorldApp: public wxApp
// {
// public:
//     virtual bool OnInit() override;
// };


// bool HelloWorldApp::OnInit()
// {
//     cout << "OnInit: Initializing Hello World app!" << endl;

//     HelloWorldFrame *frame = new HelloWorldFrame("Hello World",
//                                                  wxPoint(50, 50),
//                                                  wxSize(450, 340) );
//     frame->Show(true);
//     return true;
// }
#include "GUI_Frame.hpp"
#include "RPS_GUI.hpp"

wxBEGIN_EVENT_TABLE(GUI_Frame, wxFrame)
    EVT_MENU(wxID_ABOUT,  GUI_Frame::OnAbout)
    EVT_MENU(ID_NewGame,  GUI_Frame::OnNewGame)
    EVT_MENU(wxID_EXIT,   GUI_Frame::OnExit)
wxEND_EVENT_TABLE()

IMPLEMENT_APP(RPS_GUI)

bool RPS_GUI::OnInit()
{
    GUI_Frame *frame = new GUI_Frame(wxT("RPS_GUI"));
    frame->Show(true);

    return true;
}