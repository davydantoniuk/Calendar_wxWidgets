#ifndef NOTE_H
#define NOTE_H
#include <wx/string.h>
#include <wx/datetime.h>
#include <vector>

class Note {
public:
    wxDateTime date;
    wxString eventName;
    Note(const wxDateTime& _date, const wxString& eventName);
    Note() : date(wxDateTime::Now()), eventName(wxEmptyString) {}
    wxString GetFormattedDate() const;
};

#endif // NOTE_H
