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

IMPLEMENT_APP(RPS_GUI)

bool RPS_GUI::OnInit()
{
    GUI_Frame *frame = new GUI_Frame(wxT("RPS_GUI"));
    frame->Show(true);

    return true;
}