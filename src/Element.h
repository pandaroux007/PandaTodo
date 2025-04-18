#ifndef ELEMENT_HEADER
#define ELEMENT_HEADER

#include <wx/wx.h>

#include "pathUtils.h"

class Element : public wxPanel
{
    public:
        Element(wxWindow* parent, const wxString& labelText, bool isFolder);

    private:
        void editButtonClick(wxCommandEvent& event);
        void deleteButtonClick(wxCommandEvent& event);

        bool m_isFolder;

        wxStaticBitmap* icon;
        wxStaticText* text;
        wxButton* editButton;
        wxButton* deleteButton;
};

#endif // ELEMENT_HEADER