#include "TodoFrame.h"

TodoFrame::TodoFrame(const wxString& title)
: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    SetMinSize(wxSize(400, 300));
    SetIcon(PathUtils::loadIcon("logo.png"));

    wxPanel* mainPanel = new wxPanel(this);
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    // -------------------- top sizer with input and buttons
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);

    inputField = new wxTextCtrl(mainPanel, wxID_ANY);
    topSizer->Add(inputField, 1, wxEXPAND | wxALL, 5);
    inputField->Bind(wxEVT_TEXT, &TodoFrame::eventInputChanged, this);

    addFolderButton = new wxButton(mainPanel, wxID_ANY, "Add Folder");
    topSizer->Add(addFolderButton, 0, wxALL, 5);
    addFolderButton->Enable(false);
    addFolderButton->Bind(wxEVT_BUTTON, &TodoFrame::eventAddFolder, this);

    addTaskButton = new wxButton(mainPanel, wxID_ANY, "Add Task");
    topSizer->Add(addTaskButton, 0, wxALL, 5);
    addTaskButton->Enable(false);
    addTaskButton->Bind(wxEVT_BUTTON, &TodoFrame::eventAddTask, this);

    mainSizer->Add(topSizer, 0, wxEXPAND);

    // -------------------- scrollable zone
    scrollWindow = new wxScrolledWindow(mainPanel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL | wxHSCROLL);

    scrollWindow->SetScrollRate(5, 5);

    scrollSizer = new wxBoxSizer(wxVERTICAL);
    scrollWindow->SetSizer(scrollSizer);

    mainSizer->Add(scrollWindow, 1, wxEXPAND | wxALL, 5);
    mainPanel->SetSizer(mainSizer);
}

void TodoFrame::eventAddFolder(wxCommandEvent& event)
{
    addElement(inputField->GetValue(), true);
}

void TodoFrame::eventAddTask(wxCommandEvent& event)
{
    addElement(inputField->GetValue(), false);
}

void TodoFrame::eventInputChanged(wxCommandEvent& event)
{
    bool isInputNotEmpty = !inputField->GetValue().IsEmpty();
    
    addFolderButton->Enable(isInputNotEmpty);
    addTaskButton->Enable(isInputNotEmpty);
}

// ********************************************** private
void TodoFrame::addElement(const wxString& text, bool isFolder)
{
    Element* elementPanel = new Element(scrollWindow, text, isFolder);

    scrollSizer->Add(elementPanel, 0, wxEXPAND | wxALL, 5);

    scrollWindow->FitInside();
}