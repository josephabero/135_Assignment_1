#include "CompPanel.hpp"

void CompPanel::init()
{
    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

	wxPanel *comp_panel = new wxPanel(this, wxID_ANY);
    wxSizer *comp_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *comp_text = new wxStaticText(comp_panel, wxID_ANY,
                                                 "&Computer");
    comp_text->SetFont(comp_text->GetFont().Larger());
    wxFont font = comp_text->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    comp_text->SetFont(font);
    comp_sizer->Add(comp_text, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    comp_panel->SetSizer(comp_sizer);

    // wxPanel *results_panel = new wxPanel(this, wxID_ANY);
    // wxSizer *results_sizer = new wxBoxSizer(wxHORIZONTAL);



    // Computer wins:
    wxPanel *predict_panel = new wxPanel(this, wxID_ANY);
    wxSizer *predict_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *predict_title = new wxStaticText(predict_panel, wxID_ANY,
                                                 "Predicted Human Choice:");
    predicted_text = new wxStaticText(predict_panel, wxID_ANY, "");
    predicted_text->SetFont(predicted_text->GetFont().Larger());
    predict_sizer->Add(predict_title, 0, wxALIGN_LEFT, 0);
    predict_sizer->Add(predicted_text, 0, 0, 0);
    predict_panel->SetSizer(predict_sizer);

    // Ties:
    wxPanel *choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *choice_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *choice_title = new wxStaticText(choice_panel, wxID_ANY,
                                                 "Computer Choice:");
    choice_text = new wxStaticText(choice_panel, wxID_ANY, "");
    choice_text->SetFont(choice_text->GetFont().Larger());
    choice_sizer->Add(choice_title, 0, wxALIGN_LEFT, 0);
    choice_sizer->Add(choice_text, 0, 0, 0);
    choice_panel->SetSizer(choice_sizer);


    // results_panel->SetSizer(results_sizer);

    sizer->Add(comp_panel, 0, wxALIGN_CENTER, 0);
    sizer->Add(predict_panel, 0, wxALIGN_LEFT, 0);
    sizer->Add(choice_panel, 0, wxALIGN_LEFT, 0);
    SetSizer(sizer);
}

void CompPanel::updatePredictText(const Option option)
{
    predicted_text->SetLabelText(optionToWxString(option));
}

void CompPanel::updateChoiceText(const Option option)
{
    choice_text->SetLabelText(optionToWxString(option));
}
