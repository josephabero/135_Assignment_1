#include "ButtonPanel.hpp"

void ButtonPanel::init()
{
    // int round_number = 0;
    // round_number_text->SetLabelText(wxString::Format(wxT("%i"),round_number + 1));

    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);;

    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round:");
    round_number_text = new wxStaticText(round_panel, wxID_ANY, "");
    round_number_text->SetFont(round_number_text->GetFont());
    round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    //round_sizer->Add(round_number_text, 0, 0, 0);
    round_panel->SetSizer(round_sizer);


    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY, "Human");
    human_sizer->Add(human_text, 0, 0, 0);
    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY, "Choose:");
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

    wxStaticText *chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "Human Choice:");
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    wxPanel *computer_text_panel = new wxPanel(this, wxID_ANY);
    wxSizer *computer_text_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *computer_text_text = new wxStaticText(computer_text_panel, wxID_ANY, "Computer");
    computer_text_sizer->Add(computer_text_text, 0, 0, 0);  

    
    wxPanel *computer_panel = new wxPanel(this,wxID_ANY);
    wxSizer *computer_sizer = new wxGridSizer(2,0,5);

    wxStaticText *predicted_text_text = new wxStaticText(computer_panel,wxID_ANY, "Predicted Input:");
    predicted_text = new wxStaticText(computer_panel, wxID_ANY, "");

    wxStaticText *computer_text = new wxStaticText(computer_panel,wxID_ANY, "Computer Choice:");
    computer_chosen_text = new wxStaticText(computer_panel, wxID_ANY, "");

    computer_sizer->Add(predicted_text_text,0,wxALIGN_RIGHT,0);
    computer_sizer->Add(predicted_text,0,0,0);
    computer_sizer->Add(computer_text,0,wxALIGN_RIGHT,0);
    computer_sizer->Add(computer_chosen_text,0,0,0);
    computer_panel->SetSizer(computer_sizer);


    wxPanel *winner_panel = new wxPanel(this,wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(2,0,5);

    wxStaticText *winner_text = new wxStaticText(winner_panel,wxID_ANY, "Winner Winner:");
    
    winner_winner_text = new wxStaticText(winner_panel, wxID_ANY, "");

    winner_sizer->Add(winner_text,0,wxALIGN_RIGHT,0);
    winner_sizer->Add(winner_winner_text,0,0,0);
    winner_panel->SetSizer(winner_sizer);

    wxPanel *stats_text_panel = new wxPanel(this, wxID_ANY);
    wxSizer *stats_text_sizer = new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *stats_text_text = new wxStaticText(stats_text_panel, wxID_ANY, "Statistics");
    stats_text_sizer->Add(stats_text_text, 0, 0, 0);


    wxPanel *stats_panel = new wxPanel(this,wxID_ANY);
    wxSizer *stats_sizer = new wxGridSizer(3,2,0,5);

    wxStaticText *h_wins_text = new wxStaticText(stats_panel,wxID_ANY, "Human Wins:");
    wxStaticText *c_wins_text = new wxStaticText(stats_panel,wxID_ANY, "Computer Wins:");
    wxStaticText *ties_text = new wxStaticText(stats_panel,wxID_ANY, "Ties:");
    
    human_wins_text = new wxStaticText(stats_panel, wxID_ANY, "");
    computer_wins_text = new wxStaticText(stats_panel, wxID_ANY, "");
    current_ties_text = new wxStaticText(stats_panel, wxID_ANY, "");

    stats_sizer->Add(h_wins_text,0,wxALIGN_RIGHT,0);
    stats_sizer->Add(human_wins_text,0,wxALIGN_LEFT,0);
    stats_sizer->Add(c_wins_text,0,wxALIGN_RIGHT,0);
    stats_sizer->Add(computer_wins_text,0,0,0);
    stats_sizer->Add(ties_text,0,wxALIGN_RIGHT,0);
    stats_sizer->Add(current_ties_text,0,0,0);
    stats_panel->SetSizer(stats_sizer);


    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(computer_text_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(computer_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(stats_text_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(stats_panel, 0, wxALIGN_CENTER, 0);
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
    round_number_text->SetLabelText(optionToWxString(option));
    button_chosen_text->SetLabelText(optionToWxString(option));
    Scomp.generateOption(option);
    predicted_text->SetLabelText(optionToWxString(Scomp.getPredicted()));
    computer_chosen_text->SetLabelText(optionToWxString(Scomp.getOption()));
    //winner_winner_text->SetLabelText(winnerToWxString(game.evaluateUserWin()));
    human_wins_text->SetLabelText(optionToWxString(Scomp.getOption()));
    computer_wins_text->SetLabelText(optionToWxString(Scomp.getOption()));
    current_ties_text->SetLabelText(optionToWxString(Scomp.getOption()));
}
