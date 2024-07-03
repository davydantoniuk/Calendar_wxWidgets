#include "Note.h"
#include <wx/string.h>

Note::Note(const wxDateTime& _date, const wxString& _eventName)
    : date(_date), eventName(_eventName) {
}

wxString Note::GetFormattedDate() const {
    return date.Format(wxT("%d-%m-%Y"));
}
