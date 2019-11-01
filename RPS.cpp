// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
#include <wx/statline.h>

// ----------------------------------------------------------------------------
// event constants
// ----------------------------------------------------------------------------

// define a custom event type (we don't need a separate declaration here but
// usually you would use a matching wxDECLARE_EVENT in a header)
// wxDEFINE_EVENT(wxEVT_MY_CUSTOM_COMMAND, wxCommandEvent);

// // it may also be convenient to define an event table macro for this event type
// #define EVT_MY_CUSTOM_COMMAND(id, fn) \
//     DECLARE_EVENT_TABLE_ENTRY( \
//         wxEVT_MY_CUSTOM_COMMAND, id, wxID_ANY, \
//         wxCommandEventHandler(fn), \
//         (wxObject *) NULL \
//     ),

class MyApp: public wxApp // MyApp is the class for our application
{
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame // 
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnNewGame(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnRockChoice(wxCommandEvent& event);
    
    // the rock button to whose event we connect statically
    wxButton *m_btnRock;
    wxDECLARE_EVENT_TABLE();
};

class MyRockButton : public wxButton
{
public:
    static long BUTTON_ID;

    MyRockButton(wxWindow *parent, const wxString& label);
        // : wxButton(parent, BUTTON_ID, label);

private:
    void OnClick(wxCommandEvent& event)
    {
        wxLogMessage("Rock move selected");
    }

    wxDECLARE_EVENT_TABLE();
};



// IDs for the controls and the menu commands
enum
{
    ID_NewGame = 1,
    ID_RockButton,
    Event_Dynamic,
};



wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_NewGame,   MyFrame::OnNewGame)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
    // EVT_MENU(ID_RockButton, MyRockButton::OnClick)

    // EVT_MY_CUSTOM_COMMAND(wxID_ANY, MyFrame::OnProcessCustom)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Rock Paper Scissors: 20 rounds/game", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_NewGame, "&New Game...\tCtrl-H",
                     "Start a new game!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    menuFile->AppendSeparator();
    menuFile->Append(ID_RockButton, "Choose Rock!");
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    // menuBar->Append(ID_RockButton, "Choose Rock!");
    SetMenuBar( menuBar );

    // Panel
    wxPanel * const panel = new wxPanel(this);
    wxSizer * const mainSizer = new wxBoxSizer(wxVERTICAL);
    wxSizer * const sizer = new wxBoxSizer(wxHORIZONTAL);
    const wxSizerFlags centreY(wxSizerFlags().Centre().Border());
    sizer->Add(new wxStaticText(panel, wxID_ANY,
        "Choose: "),
        centreY);
    m_btnRock = new wxButton(panel, Event_Dynamic, "&Rock");
    sizer->Add(m_btnRock, centreY);

    mainSizer->Add(sizer, 1, wxEXPAND);
    mainSizer->Add(new wxStaticLine(panel), 0, wxEXPAND);
    mainSizer->Add(new wxStaticLine(panel), 0, wxEXPAND);

    CreateStatusBar();
    SetStatusText( "Welcome to Rock Paper Scissors game!" );
}
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Rock Paper Scissors game",
                  "About Rock Paper Scissors", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnNewGame(wxCommandEvent& event)
{
    wxLogMessage("Start a new game!");
}

void MyFrame::OnRockChoice(wxCommandEvent& event)
{
    wxLogMessage("Rock move selected");
}