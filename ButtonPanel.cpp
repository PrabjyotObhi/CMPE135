#include "ButtonPanel.h"
// #include "Scoreboard.h"
// #include "RPS.cpp"

void ButtonPanel::init()
{

    // roshambo.r_RockPaperScissor();

    wxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxPanel *round_panel = new wxPanel(this, wxID_ANY);
    wxSizer *round_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *round_text = new wxStaticText(round_panel, wxID_ANY, "Round:");
    round_text->SetFont(round_text->GetFont().Larger());

    round_sizer->Add(round_text, 0, wxALIGN_RIGHT, 0);
    
    // round_sizer->AddSpacer(5);
        

    // wxPanel *round_count_panel = new wxPanel(this, wxID_ANY);
    // wxSizer *round_count_sizer = new wxBoxSizer(wxHORIZONTAL);
    round_sizer->AddSpacer(20);
    round_count_text = new wxStaticText(round_panel, wxID_ANY, "");
    round_count_text->SetFont(round_count_text->GetFont().Larger());
    round_sizer->Add(round_count_text, 0, 0, 0);
    round_sizer->AddSpacer(20);
    // round_count_sizer->AddSpacer(10);
    // round_count_sizer->Add(round_count_text, 0, 0, 0);
    // round_count_sizer->AddSpacer(10);
    // round_count_panel->SetSizer(round_count_sizer);

    round_panel->SetSizer(round_sizer);

    wxPanel *human_panel = new wxPanel(this, wxID_ANY);
    wxSizer *human_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText *human_text = new wxStaticText(human_panel, wxID_ANY,
                                            "Human");
    human_text->SetFont(human_text->GetFont().Larger());
    
    human_sizer->Add(human_text, 0, 0, 0);
    human_sizer->AddSpacer(5);
    human_panel->SetSizer(human_sizer);

    wxPanel *button_panel = new wxPanel(this, wxID_ANY);
    wxSizer *button_sizer = new wxBoxSizer(wxHORIZONTAL);
    
    wxStaticText *choose_text = new wxStaticText(button_panel, wxID_ANY,
                                                "Choose:");
    wxButton *rock_button = new wxButton(button_panel, wxID_ANY,
                                            choice_to_wxString(ROCK));
    wxButton *paper_button = new wxButton(button_panel, wxID_ANY,
                                            choice_to_wxString(PAPER));
    wxButton *scissors_button = new wxButton(button_panel, wxID_ANY,
                                                choice_to_wxString(SCISSORS));

    rock_button->Bind   (wxEVT_BUTTON, &ButtonPanel::on_rock, this);
    paper_button->Bind  (wxEVT_BUTTON, &ButtonPanel::on_paper, this);
    scissors_button->Bind(wxEVT_BUTTON, &ButtonPanel::on_scissors, this);

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
    chosen_text->SetFont(chosen_text->GetFont().Larger());
    button_chosen_text = new wxStaticText(chosen_panel, wxID_ANY, "");
    button_chosen_text->SetFont(button_chosen_text->GetFont().Larger());
    chosen_sizer->Add(chosen_text, 0, wxALIGN_RIGHT, 0);
    chosen_sizer->Add(button_chosen_text, 0, 0, 0);
    chosen_panel->SetSizer(chosen_sizer);

    wxPanel *computer_panel = new wxPanel(this, wxID_ANY);
    wxSizer *computer_sizer = new wxGridSizer(2, 0, 5);

    wxStaticText *computer_text = new wxStaticText(computer_panel, wxID_ANY, "Computer chooses:");
    computer_chosen_text = new wxStaticText(computer_panel, wxID_ANY, "");
    computer_text->SetFont(computer_text->GetFont().Larger());
    computer_chosen_text->SetFont(computer_chosen_text->GetFont().Larger());
    computer_sizer->Add(computer_text, 0, wxALIGN_RIGHT, 0);
    computer_sizer->Add(computer_chosen_text, 0, 0, 0);
    // computer_sizer->AddSpacer(5);
    computer_panel->SetSizer(computer_sizer);

    wxPanel *human_choice_panel = new wxPanel(this,wxID_ANY);
    wxSizer *human_choice_sizer = new wxGridSizer(wxHORIZONTAL);
    wxStaticText *human_choice_text = new wxStaticText(human_choice_panel, wxID_ANY, 
                                                        "Predicted human choice: ");
    human_choice_sizer->Add(human_choice_text, 0, 0, 0);
    human_choice_sizer->AddSpacer(5);
    human_choice_panel->SetSizer(human_choice_sizer);

    wxPanel *computer_choice_panel = new wxPanel(this, wxID_ANY);
    wxSizer *computer_choice_sizer = new wxGridSizer(wxHORIZONTAL);
    wxStaticText *computer_choice_text = new wxStaticText(computer_choice_panel, wxID_ANY, "Therefore computer chooses: ");
    // computer_choice_text->AppendText("testing\n123");

    computer_choice_sizer->Add(computer_choice_text, 0, 0, 0);
    computer_choice_sizer->AddSpacer(5);
    computer_choice_panel->SetSizer(computer_choice_sizer);

    wxPanel *winner_panel = new wxPanel(this, wxID_ANY);
    wxSizer *winner_sizer = new wxGridSizer(wxHORIZONTAL);
    wxStaticText *winner_text = new wxStaticText(winner_panel, wxID_ANY, "The winner: ");
    winner_result_text = new wxStaticText(winner_panel, wxID_ANY, "");
    winner_text->SetFont(winner_text->GetFont().Larger());
    winner_result_text->SetFont(winner_result_text->GetFont().Larger());

    winner_sizer->Add(winner_text, 0, wxALIGN_RIGHT, 0);
    winner_sizer->Add(winner_result_text, 0, 0, 0);
    // winner_sizer->AddSpacer(5);
    winner_panel->SetSizer(winner_sizer);

    wxPanel *statistic_panel = new wxPanel(this, wxID_ANY);
    wxSizer *statistic_sizer = new wxGridSizer(wxHORIZONTAL);
    wxStaticText *statistic_text = new wxStaticText(statistic_panel, wxID_ANY, 
                                                "Statistics");
    wxStaticText *human_wins_text = new wxStaticText(statistic_panel, wxID_ANY,
                                                "Human wins: ");
    human_win_text = new wxStaticText(statistic_panel, wxID_ANY, "");
    // statistic_text->SetFont(statistic_text->GetFont().Larger());

    wxStaticText *computer_wins_text = new wxStaticText(statistic_panel, wxID_ANY, "Computer wins: ");
    computer_win_text = new wxStaticText(statistic_panel, wxID_ANY, "");
    wxStaticText *tie_text = new wxStaticText(statistic_panel, wxID_ANY, "Ties: ");
    tie_count_text = new wxStaticText(statistic_panel, wxID_ANY, "");
    

    statistic_sizer->Add(statistic_text, 0, wxALIGN_CENTER, 0);
    statistic_sizer->AddSpacer(10);
    statistic_sizer->Add(human_wins_text,0, wxALIGN_RIGHT,0);
    statistic_sizer->Add(human_win_text, 0, 0, 0);
    statistic_sizer->Add(computer_wins_text, 0, wxALIGN_RIGHT, 0);
    statistic_sizer->Add(computer_win_text, 0, 0, 0);
    statistic_sizer->Add(tie_text, 0, wxALIGN_RIGHT, 0);
    statistic_sizer->Add(tie_count_text, 0, 0, 0);
    // statistic_sizer->AddSpacer(5);
    statistic_panel->SetSizer(statistic_sizer);

    sizer->Add(round_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    // sizer->Add(round_count_panel, 0, wxALIGN_CENTER, 0);
    // sizer->AddSpacer(20);
    sizer->Add(human_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(chosen_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(computer_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(human_choice_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(computer_choice_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(winner_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    sizer->Add(statistic_panel, 0, wxALIGN_CENTER, 0);
    sizer->AddSpacer(20);
    

    SetSizer(sizer);
}

void ButtonPanel::on_rock(wxCommandEvent& event)
{
    if(roshambo->getRound() < 20) {
        update_button_choice_text(ROCK);
        update_winner_result_text(roshambo->playRound(ROCK));
        
        // std::cout << roshambo->playRound(ROCK) << std::endl;
        update_computer_choice_text(roshambo->getComputerChoice());
        update_round();
        update_scoreboard();
        cout << roshambo->getPlayerScore(0) << " " << roshambo->getPlayerScore(1) << " " << roshambo->getPlayerScore(2) << endl;
    }
    else {
        cout << "End of game!\n" << endl;
    }    
}

void ButtonPanel::on_paper(wxCommandEvent& event)
{
    if(roshambo->getRound() < 20) {
        update_button_choice_text(PAPER);
        update_winner_result_text(roshambo->playRound(PAPER));
        update_computer_choice_text(roshambo->getComputerChoice());
        update_round();
        update_scoreboard();
        cout << roshambo->getPlayerScore(0) << " " << roshambo->getPlayerScore(1) << " " << roshambo->getPlayerScore(2) << endl;
    }
    else {
        cout << "End of game!\n" << endl;
    }
}

void ButtonPanel::on_scissors(wxCommandEvent& event)
{
    if(roshambo->getRound() < 20) {
        update_button_choice_text(SCISSORS);
        update_winner_result_text(roshambo->playRound(SCISSORS));
        update_computer_choice_text(roshambo->getComputerChoice());
        update_round();
        update_scoreboard();
        cout << roshambo->getPlayerScore(0) << " " << roshambo->getPlayerScore(1) << " " << roshambo->getPlayerScore(2) << endl;
    }
    else {
        cout << "End of game!\n" << endl;
    }
}

void ButtonPanel::update_button_choice_text(const Choice choice)
{
    button_chosen_text->SetLabelText(choice_to_wxString(choice));
    
}

void ButtonPanel::update_computer_choice_text(const Choice choice)
{
    computer_chosen_text->SetLabelText(choice_to_wxString(choice));
}

void ButtonPanel::update_winner_result_text(const std::string winner)
{
    winner_result_text->SetLabelText(string_to_wxString(winner));
}

void ButtonPanel::update_scoreboard()
{
    human_win_text->SetLabelText(int_to_wxString(roshambo->getPlayerScore(HUMAN)));
    computer_win_text->SetLabelText(int_to_wxString(roshambo->getPlayerScore(COMPUTER)));
    tie_count_text->SetLabelText(int_to_wxString(roshambo->getPlayerScore(TIE)));
}

void ButtonPanel::update_round()
{
    cout << "Updating round to " << roshambo->getRound() << endl;
    round_count_text->SetLabelText(int_to_wxString(roshambo->getRound()));
    // round_count_text->SetLabelText(string_to_wxString(to_string(roshambo->getRound())));
}
