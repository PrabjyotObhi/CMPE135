// wxWidgets "Hello world" Program
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class MyFrame: public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnNewGame(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

enum
{
    ID_NewGame = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_NewGame,   MyFrame::OnNewGame)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
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
    menuFile->Append(wxID_EXIT, "&xit\tCtrl-X",
                     "Quit RPS game");
        
    menuFile->AppendSeparator();
            
   // menuFile->Append(wxID_EXIT);
            
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
            
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&Options" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
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