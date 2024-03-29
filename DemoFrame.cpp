#include "DemoFrame.h"

// The event table.
wxBEGIN_EVENT_TABLE(DemoFrame, wxFrame)
    EVT_MENU(RPS_New_Game, DemoFrame::on_new_game)
    EVT_MENU(RPS_Quit,  DemoFrame::on_quit)
    EVT_MENU(RPS_About, DemoFrame::on_about)
wxEND_EVENT_TABLE()

const int SIDE_MARGINS = 40;

DemoFrame::DemoFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title),
      button_panel(new ButtonPanel(this))
{
    init();

    wxSize size = GetSize();
    size.SetWidth (size.GetWidth() + SIDE_MARGINS);
    SetSize(size);
}

DemoFrame::~DemoFrame()
{
    delete button_panel;
}

void DemoFrame::init()
{
    init_menu_bar();
    init_sizer();

    wxSize size = GetBestSize();
    SetMinClientSize(size);
}

void DemoFrame::init_menu_bar()
{
    wxMenu *fileMenu = new wxMenu;
    fileMenu->Append(RPS_New_Game, "&New Game\tN", "Start new game");
    fileMenu->Append(RPS_Quit,  "E&xit\tAlt-X", "Quit program");
    
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(RPS_About, "&About\tF1",   "Show about dialog");

    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");
    SetMenuBar(menuBar);
}

void DemoFrame::init_sizer()
{
    wxSizer *frame_sizer = new wxBoxSizer(wxVERTICAL);

    frame_sizer->AddSpacer(20);
    frame_sizer->Add(button_panel, 0, wxALIGN_CENTER, 0);

    SetSizerAndFit(frame_sizer);
}

void DemoFrame::on_about(wxCommandEvent& WXUNUSED(event))
{
    wxMessageBox(wxString::Format(
                    "This is a Rock Paper Scissors game\n"
                    "built with %s\n"
                    "and running under %s.\n"
                    "Developed by Team MakChickens\n"
                    "CMPE 135, Fall 2019",
                    wxVERSION_STRING,
                    wxGetOsDescription()
                ),
                "About the RPS game",
                wxOK | wxICON_INFORMATION,
                this);
}

void DemoFrame::on_quit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);  // true is to force the frame to close
}

void DemoFrame::on_new_game(wxCommandEvent& WXUNUSED(event))
{
    button_panel->new_game();
}