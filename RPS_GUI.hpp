#ifndef	RPS_GUI_HPP
#define	RPS_GUI_HPP

#include <wx/wx.h>
#include "game/game.hpp"
class RPS_GUI : public wxApp
{
  public:
    virtual bool OnInit();
};

#endif