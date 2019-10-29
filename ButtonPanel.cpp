#include "ButtonPanel.hpp"

void ButtonPanel::init()
{
    round_number = 1;
    round_max = 20;

    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *max_round_panel = new wxPanel(this,wxID_ANY);
    wxSizer *max_round_sizer = new wxGridSizer(2,0,5);

    const char *up = "Max Round Up";
    const char *down = "Max Round Down";
    
    wxString upstring = wxString::FromUTF8(up);
    wxString downstring = wxString::FromUTF8(down);
    
    wxButton *up_button = new wxButton(max_round_panel, wxID_ANY, upstring );
    wxButton *down_button = new wxButton(max_round_panel, wxID_ANY, downstring );
    
    up_button->Bind (wxEVT_BUTTON, &ButtonPanel::onUp,this);
    down_button->Bind(wxEVT_BUTTON, &ButtonPanel::onDown,this);

    wxStaticText *max_round_text = new wxStaticText(max_round_panel, wxID_ANY, "Max Round:");

     max_round_number_text = new wxStaticText(max_round_panel, wxID_ANY, "");
    max_round_number_text->SetFont(max_round_number_text->GetFont());
    
    max_round_sizer->Add(max_round_number_text,0,wxALIGN_RIGHT,0);
    max_round_sizer->AddSpacer(5);
    max_round_sizer->Add(up_button,0,0,0);
    max_round_sizer->AddSpacer(5);
    max_round_sizer->Add(down_button,0,0,0);
    max_round_panel->SetSizer(max_round_sizer);

    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxGridSizer(2, 0, 5);
    
    
    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round:");
    

   
    round_number_text = new wxStaticText(round_panel, wxID_ANY, "");
    round_number_text->SetFont(round_number_text->GetFont());
    round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    round_sizer->Add(round_number_text, 0, 0, 0);
    round_sizer->AddSpacer(5);
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

    sizer->Add(max_round_panel,0, wxALIGN_LEFT, 0);
    sizer->AddSpacer(20);
    sizer->Add(round_panel, 0, wxALIGN_LEFT, 0);
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
void ButtonPanel::Increment_Round()
{
    round_max++;
}
void ButtonPanel::Decrement_Round()
{
    if(round_max == 1)
    {
        round_max = 1;
    }
    else
    {
        round_max --;
    }
   
}
void ButtonPanel::onUp(wxCommandEvent& event)
{
    //updateButtonOption(Option::ROCK);
    Increment_Round();
    wxString max_round = wxString::Format(wxT("%i"),round_max);
    max_round_number_text->SetLabelText(max_round);

}
void ButtonPanel::onDown(wxCommandEvent& event)
{
   // updateButtonOption(Option::ROCK);
   Decrement_Round();
   wxString max_round = wxString::Format(wxT("%i"),round_max);
    max_round_number_text->SetLabelText(max_round);

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
void ButtonPanel::ZeroScore()
{
    round_number = 1;
    wxString round = wxString::Format(wxT("%i"),round_number);
    round_number_text->SetLabelText(round);
    Human.setScore(0);
    Computer.setScore(0);
    Tie.setScore(0);
    wxString Zero = wxString::Format(wxT("%i"),Human.getScore());
    human_wins_text->SetLabelText(Zero);
    computer_wins_text->SetLabelText(Zero);
    current_ties_text->SetLabelText(Zero);
}
void ButtonPanel::updateButtonOption(const Option option)
{
    Winner result;
    
    //Round Implementation
    if(round_number > round_max)
    {
       wxMessageBox( "Game is over! Please press New Game under the file tab! Or increase Max Round Counter.",
                  "GAME OVER", wxOK | wxICON_INFORMATION );
    }
    else
    {
    wxString max_round = wxString::Format(wxT("%i"),round_max);
    max_round_number_text->SetLabelText(max_round);
    wxString round = wxString::Format(wxT("%i"),round_number);
    round_number_text->SetLabelText(round);
    round_number = round_number + 1;
    wxString temp;
    
    
    //Button
    button_chosen_text->SetLabelText(optionToWxString(option));
    
    //Computer 
    Scomp.generateOption(option);
    predicted_text->SetLabelText(optionToWxString(Scomp.getPredicted()));
    computer_chosen_text->SetLabelText(optionToWxString(Scomp.getOption()));

    //Winner
    winner_winner_text->SetLabelText(winnerToWxString(game.evaluateWin(option,Scomp.getOption())));
    
    //Scoring Section
    temp = wxString::Format(wxT("%i"),Human.getScore());
    human_wins_text->SetLabelText(temp);
    temp = wxString::Format(wxT("%i"),Computer.getScore());
    computer_wins_text->SetLabelText(temp);
    temp = wxString::Format(wxT("%i"),Tie.getScore());
    current_ties_text->SetLabelText(temp);
    result = game.evaluateWin(option, Scomp.getOption());
    if(result == Winner::YOU)
    {
        Human.incrementScore();
        temp = wxString::Format(wxT("%i"),Human.getScore());
        human_wins_text->SetLabelText(temp);
    }
    else if(result == Winner::COMPUTER)
    {
        Computer.incrementScore();
        temp = wxString::Format(wxT("%i"),Computer.getScore());
        computer_wins_text->SetLabelText(temp);
    }
    else
    {
        Tie.incrementScore();
        temp = wxString::Format(wxT("%i"),Tie.getScore());
        current_ties_text->SetLabelText(temp);
    }
    }
}
