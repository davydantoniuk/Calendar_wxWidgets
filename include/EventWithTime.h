#ifndef EVENTWITHTIME_H
#define EVENTWITHTIME_H
#include <wx/string.h>
#include <wx/datetime.h>
class EventWithTime
{
    public:
        wxString eventName;
        wxDateTime eventDateTime;
        EventWithTime() : eventName(wxEmptyString), eventDateTime(wxDateTime::Now()) {}
        EventWithTime(const wxString& name, const wxDateTime& dateTime);
        virtual ~EventWithTime();

    protected:

    private:
};

#endif // EVENTWITHTIME_H
