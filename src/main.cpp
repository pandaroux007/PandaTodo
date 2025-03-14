#include <wx/wx.h>
// #include <wx/xrc/xmlres.h>

class PandaTodo : public wxApp
{
    public:
        virtual bool OnInit()
        {
            return EXIT_SUCCESS;
        }
};

wxIMPLEMENT_APP(PandaTodo);