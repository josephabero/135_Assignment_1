#include "GUI_Frame.hpp"


GUI_Frame::GUI_Frame(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150))
{
  	Centre();
}