#ifndef TODO_FRAME_HEADER
#define TODO_FRAME_HEADER

#include <wx/wx.h>

#include "about.h"
#include "debug.h"
#include "pathUtils.h"
#include "Element.h"

class TodoFrame : public wxFrame
{
    public:
        TodoFrame(const wxString& title);
        void eventAddFolder(wxCommandEvent& event);
        void eventAddTask(wxCommandEvent& event);
        void eventInputChanged(wxCommandEvent& event);

    private:
        wxTextCtrl* inputField;
        wxButton* addFolderButton;
        wxButton* addTaskButton;
        wxScrolledWindow* scrollWindow;
        wxBoxSizer* scrollSizer;

        void addElement(const wxString& text, bool isFolder);
};

#endif // TODO_FRAME_HEADER