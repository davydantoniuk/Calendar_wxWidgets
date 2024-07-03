#include "EventWithTime.h"
#include <wx/string.h>

EventWithTime::EventWithTime(const wxString& name, const wxDateTime& dateTime)
{
    eventName = name;
    eventDateTime = dateTime;
}

EventWithTime::~EventWithTime()
{
    //dtor
}
