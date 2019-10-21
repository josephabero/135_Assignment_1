#include "ButtonPanel.hpp"

void ButtonPanel::init()
{
    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxGridSizer(2, 0, 5);
    wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY,
                                                 "Human");
    human_text->SetFont(human_text->GetFont().Larger());
    wxFont font = human_text->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    human_text->SetFont(font);
    human_sizer->Add(human_text, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    human_panel->SetSizer(human_sizer);


    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                 "Choose:");
    wxButton *rock_button     = new wxButton(button_panel, wxID_ANY,
                                             optionToWxString(Option::ROCK));
    wxButton *paper_button    = new wxButton(button_panel, wxID_ANY,
                                             optionToWxString(Option::PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                             optionToWxString(Option::SCISSORS));

    rock_button->Bind    (wxEVT_BUTTON, &ButtonPanel::onRock, this);
    paper_button->Bind   (wxEVT_BUTTON, &ButtonPanel::onPaper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::onScissors, this);

    button_sizer->Add(choose_text, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(rock_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(paper_button, 0, 0, 0);
    button_sizer->AddSpacer(5);
    button_sizer->Add(scissors_button, 0, 0, 0);
    button_panel->SetSizer(button_sizer);

    wxPanel *chosen_panel = new wxPanel(this, wxID_ANY);
    wxSizer *chosen_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY,
                                                 "Human chooses:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(5);
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);

    SetSizer(sizer);
}

void ButtonPanel::onRock(wxCommandEvent& event)
{
    updateButtonOption(Option::ROCK);
}

void ButtonPanel::onPaper(wxCommandEvent& event)
{
    updateButtonOption(Option::PAPER);
}

void ButtonPanel::onScissors(wxCommandEvent& event)
{
    updateButtonOption(Option::SCISSORS);
}

void ButtonPanel::updateButtonOption(const Option option)
{
    button_chosen_text->SetLabelText(optionToWxString(option));
}
