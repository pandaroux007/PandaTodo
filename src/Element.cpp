#include "Element.h"

Element::Element(wxWindow* parent, const wxString& labelText, bool isFolder)
: wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE), m_isFolder(isFolder)
{
    auto* sizer = new wxBoxSizer(wxHORIZONTAL);

    icon = new wxStaticBitmap(this, wxID_ANY, m_isFolder ? PathUtils::loadBitmap("folder.png") : PathUtils::loadBitmap("task.png"));
    sizer->Add(icon, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    text = new wxStaticText(this, wxID_ANY, labelText, wxDefaultPosition, wxDefaultSize);
    sizer->Add(text, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    editButton = new wxButton(this, wxID_ANY, "", wxDefaultPosition, wxSize(45, 45));
    editButton->SetBitmap(PathUtils::loadBitmap("edit.png"));
    editButton->Bind(wxEVT_BUTTON, &Element::editButtonClick, this);
    sizer->Add(editButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    deleteButton = new wxButton(this, wxID_ANY, "", wxDefaultPosition, wxSize(45, 45));
    deleteButton->SetBitmap(PathUtils::loadBitmap("delete.png"));
    deleteButton->Bind(wxEVT_BUTTON, &Element::deleteButtonClick, this);
    sizer->Add(deleteButton, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    SetSizerAndFit(sizer);
}

void Element::editButtonClick(wxCommandEvent& event)
{
    wxString typeTextDialog = m_isFolder ? "folder" : "task";
    auto* dialog = new wxTextEntryDialog(this, "Modify the text of " + typeTextDialog + ":", "Modify the text");
    
    if(dialog->ShowModal() == wxID_OK)
    {
        text->SetLabel(dialog->GetValue());
        GetParent()->Layout();
    }
}

void Element::deleteButtonClick(wxCommandEvent& event)
{
    GetParent()->GetSizer()->Detach(this);
    Destroy();
}