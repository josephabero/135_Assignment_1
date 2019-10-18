#include <iostream>
#include <wx/wx.h>

using namespace std;

class HelloWorldApp: public wxApp
{
public:
    virtual bool OnInit() override;
};

class HelloWorldFrame: public wxFrame
{
public:
    HelloWorldFrame(const wxString& title,
                    const wxPoint& pos, const wxSize& size);

private:
    void OnHello(wxCommandEvent& event);
    void OnBonjour(wxCommandEvent& event);
    void OnGutenTag(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_Hello    = 1,
    ID_Bonjour  = 2,
    ID_GutenTag = 3
};

wxBEGIN_EVENT_TABLE(HelloWorldFrame, wxFrame)
    EVT_MENU(ID_Hello,    HelloWorldFrame::OnHello)
    EVT_MENU(ID_Bonjour,  HelloWorldFrame::OnBonjour)
    EVT_MENU(ID_GutenTag, HelloWorldFrame::OnGutenTag)
    EVT_MENU(wxID_ABOUT,  HelloWorldFrame::OnAbout)
    EVT_MENU(wxID_EXIT,   HelloWorldFrame::OnExit)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(HelloWorldApp);

bool HelloWorldApp::OnInit()
{
    cout << "OnInit: Initializing Hello World app!" << endl;

    HelloWorldFrame *frame = new HelloWorldFrame("Hello World",
                                                 wxPoint(50, 50),
                                                 wxSize(450, 340) );
    frame->Show(true);
    return true;
}

HelloWorldFrame::HelloWorldFrame(const wxString& title,
                 const wxPoint& pos, const wxSize& size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Status string: Hello!");
    menuFile->AppendSeparator();
    menuFile->Append(ID_Bonjour, "&Bonjour...\tCtrl-B",
                     "Status string: Bonjour!");
    menuFile->Append(ID_GutenTag, "&Guten Tag...\tCtrl-G",
                     "Status string: Guten Tag!");
    menuFile->Append(wxID_EXIT, "E&xit...\tCtrl-X",
                     "Status string: Quit Wx-helloworld");

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to the Hello World app!");
}

void HelloWorldFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void HelloWorldFrame::OnExit(wxCommandEvent& event)
{
    cout << "OnExit: Exiting Hello World app!" << endl;
    Close(true);
}

void HelloWorldFrame::OnHello(wxCommandEvent& event)
{
    wxMessageBox( "Hello, world!",
                  "OnHello", wxOK | wxICON_INFORMATION );
}

void HelloWorldFrame::OnBonjour(wxCommandEvent& event)
{
    wxMessageBox( "Bonjour, monde!",
                  "OnBonjour", wxOK | wxICON_INFORMATION );
}

void HelloWorldFrame::OnGutenTag(wxCommandEvent& event)
{
    wxMessageBox( "Guten Tag, Welt!",
                  "OnGutenTag", wxOK | wxICON_INFORMATION );
}