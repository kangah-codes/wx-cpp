//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
#include "app.h"

MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: MyFrame::MyFrame
    SetSize(wxSize(600, 500));
    TestApp_menubar = new wxMenuBar();
    wxMenu *wxglade_tmp_menu;
    wxglade_tmp_menu = new wxMenu();
    TestApp_menubar->Append(wxglade_tmp_menu, wxT("Home"));
    wxglade_tmp_menu = new wxMenu();
    TestApp_menubar->Append(wxglade_tmp_menu, wxT("About"));
    wxglade_tmp_menu = new wxMenu();
    TestApp_menubar->Append(wxglade_tmp_menu, wxT("item"));
    SetMenuBar(TestApp_menubar);
    todos = new wxListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_HRULES|wxLC_REPORT|wxLC_VRULES);

    set_properties();
    do_layout();
    // end wxGlade
}


void MyFrame::set_properties()
{
    // begin wxGlade: MyFrame::set_properties
    SetTitle(wxT("TestApp"));
    todos->SetMinSize(wxSize(-1, -1));
    todos->SetFont(wxFont(10, wxDEFAULT, wxNORMAL, wxNORMAL, 0, wxT("Sans")));
    todos->AppendColumn(wxT("A"), wxLIST_FORMAT_LEFT, -1)
    todos->AppendColumn(wxT("B"), wxLIST_FORMAT_LEFT, -1)
    todos->AppendColumn(wxT("C"), wxLIST_FORMAT_LEFT, -1)
    // end wxGlade
}


void MyFrame::do_layout()
{
    // begin wxGlade: MyFrame::do_layout
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    sizer_1->Add(todos, 1, wxEXPAND, 0);
    SetSizer(sizer_1);
    Layout();
    // end wxGlade
}


class MyApp: public wxApp {
public:
    bool OnInit();
};

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    wxInitAllImageHandlers();
    MyFrame* TestApp = new MyFrame(NULL, wxID_ANY, wxEmptyString);
    SetTopWindow(TestApp);
    TestApp->Show();
    return true;
}
