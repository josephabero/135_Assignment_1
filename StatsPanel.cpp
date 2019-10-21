#include "StatsPanel.hpp"

void StatsPanel::init()
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *stats_panel = new wxPanel(this, wxID_ANY);
    wxSizer *stats_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *stats_text = new wxStaticText(stats_panel, wxID_ANY,
                                                 "&Statistics");
    stats_text->SetFont(stats_text->GetFont().Larger());
    wxFont font = stats_text->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    stats_text->SetFont(font);
    stats_sizer->Add(stats_text, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    stats_panel->SetSizer(stats_sizer);

    // wxPanel *results_panel = new wxPanel(this, wxID_ANY);
    // wxSizer *results_sizer = new wxBoxSizer(wxHORIZONTAL);


    // Human wins: 
    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *human_title = new wxStaticText(human_panel, wxID_ANY,
                                                 "Human wins:");
    human_wins_text = new wxStaticText(human_panel, wxID_ANY, "");
    human_wins_text->SetFont(human_wins_text->GetFont().Larger());
    human_sizer->Add(human_title, 0, wxALIGN_LEFT, 0);
    human_sizer->Add(human_wins_text, 0, 0, 0);
    human_panel->SetSizer(human_sizer);

    // Computer wins:
    wxPanel *comp_panel = new wxPanel(this, wxID_ANY);
    wxSizer *comp_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *comp_title = new wxStaticText(comp_panel, wxID_ANY,
                                                 "Computer wins:");
    comp_wins_text = new wxStaticText(comp_panel, wxID_ANY, "");
    comp_wins_text->SetFont(comp_wins_text->GetFont().Larger());
    comp_sizer->Add(comp_title, 0, wxALIGN_LEFT, 0);
    comp_sizer->Add(comp_wins_text, 0, 0, 0);
    comp_panel->SetSizer(comp_sizer);

    // Ties:
    wxPanel *ties_panel = new wxPanel(this, wxID_ANY);
    wxSizer *ties_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *ties_title = new wxStaticText(ties_panel, wxID_ANY,
                                                 "Ties:");
    ties_text = new wxStaticText(ties_panel, wxID_ANY, "");
    ties_text->SetFont(ties_text->GetFont().Larger());
    ties_sizer->Add(ties_title, 0, wxALIGN_LEFT, 0);
    ties_sizer->Add(ties_text, 0, 0, 0);
    ties_panel->SetSizer(ties_sizer);


    // results_panel->SetSizer(results_sizer);

    sizer->Add(stats_panel, 0, wxALIGN_CENTER, 0);
    sizer->Add(human_panel, 0, wxALIGN_LEFT, 0);
    sizer->Add(comp_panel, 0, wxALIGN_LEFT, 0);
    sizer->Add(ties_panel, 0, wxALIGN_LEFT, 0);
    SetSizer(sizer);
}


void StatsPanel::updateHumanWins(const int count)
{
    human_wins_text->SetLabelText(wxString::Format(wxT("%i"), count));
}

void StatsPanel::updateCompWins(const int count)
{
    comp_wins_text->SetLabelText(wxString::Format(wxT("%i"), count));
}

void StatsPanel::updateTies(const int count)
{
    ties_text->SetLabelText(wxString::Format(wxT("%i"), count));
}
