#include "RoundCount.hpp"

void RoundCountPanel::init()
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *round_title = new wxStaticText(round_panel, wxID_ANY,
                                                 "&Round:");

    round_text = new wxStaticText(round_panel, wxID_ANY, "");
    round_text->SetFont(round_text->GetFont().Larger());

    // Bolds "Round:"
    round_title->SetFont(round_title->GetFont().Larger());
    wxFont font = round_title->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    round_title->SetFont(font);

    // Bolds Round Count
    round_text->SetFont(round_text->GetFont().Larger());
    font = round_text->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    round_text->SetFont(font);

    round_sizer->Add(round_title, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    round_sizer->Add(round_text, 0, 0, 0);
    round_panel->SetSizer(round_sizer);

    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    SetSizer(sizer);
}

void RoundCountPanel::updateRoundCount(const int count)
{
    round_text->SetLabelText(wxString::Format(wxT("%i"), count));
}