#ifndef PATH_UTILS_HEADER
#define PATH_UTILS_HEADER

#include <wx/wx.h>
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include "debug.h"

class PathUtils
{
    private:
        static wxString getAssetsPath()
        {
            wxStandardPaths& paths = wxStandardPaths::Get();
            wxString executableDir = wxFileName(paths.GetExecutablePath()).GetPath();
            return executableDir + "/../assets";
        }

    public:
        static wxBitmap loadBitmap(const wxString& filename)
        {
            wxString fullPath = getAssetsPath() + "/" + filename;
            return wxBitmap(fullPath, wxBITMAP_TYPE_PNG);
        }

        static wxIcon loadIcon(const wxString& filename)
        {
            wxString fullPath = getAssetsPath() + "/" + filename;
            wxIcon icon;
            if (icon.LoadFile(fullPath, wxBITMAP_TYPE_PNG))
            {
                return icon;
            }
            else
            {
                LOG_MSG_NL("Unable to load icon from this path : " + fullPath);
                return wxIcon();
            }
        }
};

#endif // PATH_UTILS_HEADER