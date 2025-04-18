#include <wx/wx.h>
#include "TodoFrame.h"

class PandaTodo : public wxApp
{
    public:
        virtual bool OnInit()
        {
            wxImage::AddHandler(new wxPNGHandler());
            
            TodoFrame* frame = new TodoFrame(wxString::Format("%s - %s", APP_NAME, APP_VERSION));
            frame->Show(true);

            return true;
        }
};

wxIMPLEMENT_APP(PandaTodo);