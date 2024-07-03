/***************************************************************
 * Name:      KalendarzMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-12-29
 * Copyright:  ()
 * License:
 **************************************************************/

#include "KalendarzMain.h"
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
#include "EventWithTime.h"
#include <wx/datetime.h>
#include <wx/filedlg.h>
#include <wx/textfile.h>
#include <wx/tokenzr.h>
#include <wx/listctrl.h>
#include <wx/datectrl.h>
#include <wx/log.h>
#include <wx/intl.h>
#include <algorithm>
#include <wx/msgdlg.h>

//(*InternalHeaders(KalendarzDialog)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

#undef _
#define _(s) wxString::FromUTF8(s)

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(KalendarzDialog)
const long KalendarzDialog::ID_COMBOBOX1 = wxNewId();
const long KalendarzDialog::ID_CHOICE1 = wxNewId();
const long KalendarzDialog::ID_COMBOBOX2 = wxNewId();
const long KalendarzDialog::ID_BUTTON3 = wxNewId();
const long KalendarzDialog::ID_BUTTON9 = wxNewId();
const long KalendarzDialog::ID_CALENDARCTRL1 = wxNewId();
const long KalendarzDialog::ID_CHECKLISTBOX1 = wxNewId();
const long KalendarzDialog::ID_LISTBOX1 = wxNewId();
const long KalendarzDialog::ID_BUTTON1 = wxNewId();
const long KalendarzDialog::ID_BUTTON2 = wxNewId();
const long KalendarzDialog::ID_BUTTON5 = wxNewId();
const long KalendarzDialog::ID_BUTTON6 = wxNewId();
const long KalendarzDialog::ID_BUTTON7 = wxNewId();
const long KalendarzDialog::ID_BUTTON8 = wxNewId();
const long KalendarzDialog::ID_BUTTON4 = wxNewId();
const long KalendarzDialog::ID_STATICTEXT1 = wxNewId();
const long KalendarzDialog::ID_LISTBOX2 = wxNewId();
const long KalendarzDialog::ID_TIMER1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KalendarzDialog,wxDialog)
    //(*EventTable(KalendarzDialog)
    //*)
END_EVENT_TABLE()

KalendarzDialog::KalendarzDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(KalendarzDialog)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxFlexGridSizer* FlexGridSizer7;
    wxFlexGridSizer* FlexGridSizer8;
    wxFlexGridSizer* FlexGridSizer9;

    Create(parent, wxID_ANY, _("Kalendarz"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(1);
    FlexGridSizer2 = new wxFlexGridSizer(0, 6, 0, 0);
    FlexGridSizer2->AddGrowableCol(0);
    FlexGridSizer2->AddGrowableCol(1);
    FlexGridSizer2->AddGrowableCol(2);
    FlexGridSizer2->AddGrowableCol(3);
    FlexGridSizer2->AddGrowableCol(4);
    FlexGridSizer2->AddGrowableCol(5);
    FlexGridSizer2->AddGrowableRow(0);
    ComboBox1 = new wxComboBox(this, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    FlexGridSizer2->Add(ComboBox1, 1, wxALL|wxEXPAND, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer2->Add(Choice1, 1, wxALL|wxEXPAND, 5);
    ComboBox2 = new wxComboBox(this, ID_COMBOBOX2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX2"));
    FlexGridSizer2->Add(ComboBox2, 1, wxALL|wxEXPAND, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Znajdź"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer2->Add(Button3, 1, wxALL|wxEXPAND, 5);
    Button9 = new wxButton(this, ID_BUTTON9, _("Info"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
    FlexGridSizer2->Add(Button9, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer3->AddGrowableCol(0);
    FlexGridSizer3->AddGrowableCol(1);
    FlexGridSizer3->AddGrowableRow(0);
    CalendarCtrl1 = new wxCalendarCtrl(this, ID_CALENDARCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_SHOW_HOLIDAYS, _T("ID_CALENDARCTRL1"));
    CalendarCtrl1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_HOTLIGHT));
    wxFont CalendarCtrl1Font(10,wxFONTFAMILY_ROMAN,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Times New Roman"),wxFONTENCODING_DEFAULT);
    CalendarCtrl1->SetFont(CalendarCtrl1Font);
    FlexGridSizer3->Add(CalendarCtrl1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer9 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer9->AddGrowableCol(0);
    FlexGridSizer9->AddGrowableCol(1);
    FlexGridSizer9->AddGrowableRow(0);
    CheckListBox1 = new wxCheckListBox(this, ID_CHECKLISTBOX1, wxDefaultPosition, wxSize(204,141), 0, 0, wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_CHECKLISTBOX1"));
    FlexGridSizer9->Add(CheckListBox1, 1, wxALL|wxEXPAND, 5);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(221,141), 0, 0, wxVSCROLL|wxHSCROLL, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer9->Add(ListBox1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer3->Add(FlexGridSizer9, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    FlexGridSizer4->AddGrowableRow(0);
    FlexGridSizer5 = new wxFlexGridSizer(5, 0, 0, 0);
    FlexGridSizer6 = new wxFlexGridSizer(0, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Dodaj zdarzenie"), wxDefaultPosition, wxSize(122,23), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer6->Add(Button1, 1, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Dodaj notatkę"), wxDefaultPosition, wxSize(116,23), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer6->Add(Button2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer5->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer7 = new wxFlexGridSizer(0, 2, 0, 0);
    Button5 = new wxButton(this, ID_BUTTON5, _("Wszystkie zdarzenia"), wxDefaultPosition, wxSize(122,23), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    FlexGridSizer7->Add(Button5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(this, ID_BUTTON6, _("Wszystkie notatki"), wxDefaultPosition, wxSize(116,-1), 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer7->Add(Button6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer8 = new wxFlexGridSizer(0, 2, 0, 0);
    Button7 = new wxButton(this, ID_BUTTON7, _("Wklej"), wxDefaultPosition, wxSize(122,23), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    FlexGridSizer8->Add(Button7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button8 = new wxButton(this, ID_BUTTON8, _("Zapisz"), wxDefaultPosition, wxSize(116,23), 0, wxDefaultValidator, _T("ID_BUTTON8"));
    FlexGridSizer8->Add(Button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5->Add(FlexGridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Usuń"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer5->Add(Button4, 1, wxALL|wxEXPAND, 5);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    StaticText1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    FlexGridSizer5->Add(StaticText1, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer4->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ListBox2 = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxSize(300,49), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
    FlexGridSizer4->Add(ListBox2, 1, wxALL|wxEXPAND, 5);
    FlexGridSizer1->Add(FlexGridSizer4, 1, wxALL|wxEXPAND, 5);
    SetSizer(FlexGridSizer1);
    Timer1.SetOwner(this, ID_TIMER1);
    Timer1.Start(17, false);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_COMBOBOX1,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&KalendarzDialog::OnComboBox1Selected);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&KalendarzDialog::OnChoice1Select1);
    Connect(ID_COMBOBOX2,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&KalendarzDialog::OnComboBox2Selected);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton3Click);
    Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton9Click);
    Connect(ID_CALENDARCTRL1,wxEVT_CALENDAR_SEL_CHANGED,(wxObjectEventFunction)&KalendarzDialog::OnCalendarCtrl1Changed);
    Connect(ID_CALENDARCTRL1,wxEVT_CALENDAR_DOUBLECLICKED,(wxObjectEventFunction)&KalendarzDialog::OnCalendarCtrl1DblClicked);
    Connect(ID_CHECKLISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&KalendarzDialog::OnCheckListBox1DClick);
    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,(wxObjectEventFunction)&KalendarzDialog::OnListBox1DClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton2Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton6Click);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton7Click);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton8Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KalendarzDialog::OnButton4Click);
    Connect(ID_TIMER1,wxEVT_TIMER,(wxObjectEventFunction)&KalendarzDialog::OnTimer1Trigger);
    Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&KalendarzDialog::OnInit);
    //*)

    InitComboBoxes();
    InitHolidays(holidays);
    SetIcon(wxICON(aaaa));

}

KalendarzDialog::~KalendarzDialog()
{
    //(*Destroy(KalendarzDialog)
    //*)
}

void KalendarzDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void KalendarzDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void KalendarzDialog::OnInit(wxInitDialogEvent& event)
{

}

void KalendarzDialog::OnTimer1Trigger(wxTimerEvent& event)
{
    wxDateTime now = wxDateTime::Now();
    wxString timeStr = now.FormatTime();
    StaticText1->SetLabel(timeStr);
}

void KalendarzDialog::OnCalendarCtrl1DblClicked(wxCalendarEvent& event)
{

    wxDateTime selectedDate = CalendarCtrl1->GetDate();

    ComboBox1->SetValue(wxString::Format("%d", selectedDate.GetDay()));

    int selectedMonth = selectedDate.GetMonth();
    Choice1->SetSelection(selectedMonth);

    ComboBox2->SetValue(wxString::Format("%d", selectedDate.GetYear()));

    wxCommandEvent buttonEvent(wxEVT_BUTTON, Button3->GetId());

    buttonEvent.SetEventObject(Button3);

    OnButton3Click(buttonEvent);
}

int GetDaysInMonth(int year, int month)
{
    if (month < 1 || month > 12) {
        return 0;
    }

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;

        case 4:
        case 6:
        case 9:
        case 11:
            return 30;

        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default:
            return 0;
    }
}

void KalendarzDialog::UpdateDaysList()
{
    if (selectedMonth == 0) {
        return;
    }

    int selectedYear = wxAtoi(ComboBox2->GetValue());

    if (selectedYear == 0) {
        return;
    }

    int daysInMonth = GetDaysInMonth(selectedYear, selectedMonth);
    wxString selectedValue = ComboBox1->GetValue();
    ComboBox1->Clear();

    for (int day = 1; day <= daysInMonth; ++day) {
        wxString dayString = wxString::Format("%d", day);
        ComboBox1->Append(dayString);
    }

    int selectedIndex = ComboBox1->FindString(selectedValue);

    if (selectedIndex != wxNOT_FOUND) {
        ComboBox1->SetSelection(selectedIndex);
    }
}

void KalendarzDialog::InitComboBoxes()
{
    for (int day = 1; day <= 31; ++day) {
        wxString dayString = wxString::Format("%d", day);
        ComboBox1->Append(dayString);
    }

    wxString months[] = {
        _("Styczeń"), _("Luty"), _("Marzec"), _("Kwiecień"),
        _("Maj"), _("Czerwiec"), _("Lipiec"), _("Sierpień"),
        _("Wrzesień"), _("Październik"), _("Listopad"), _("Grudzień")
    };

    for (const wxString& month : months) {
        Choice1->Append(month);
    }

    wxDateTime currentDate = wxDateTime::Now();
    const int maxYear = 2000;
    for (int year = maxYear; year <= currentDate.GetYear()+25; ++year) {
        wxString yearString = wxString::Format("%d", year);
        ComboBox2->Append(yearString);
    }

    UpdateDaysList();
}

void KalendarzDialog::OnComboBox1Selected(wxCommandEvent& event)
{

}

void KalendarzDialog::OnChoice1Select1(wxCommandEvent& event)
{
    selectedMonth = Choice1->GetSelection() + 1;
    UpdateDaysList();
}

void KalendarzDialog::OnComboBox2Selected(wxCommandEvent& event)
{
    UpdateDaysList();
}

bool KalendarzDialog::IsDateValid(int day, int month, int year)
{
    if (year < 0 || month < 1 || month > 12 || day < 1)
    {
        return false;
    }
    int daysInMonth = GetDaysInMonth(selectedYear, selectedMonth);
    if (day > daysInMonth)
    {
        return false;
    }
    return true;
}


void KalendarzDialog::UpdateCalendarDate()
{
    selectedHolidays.clear();
    selectedDay = wxAtoi(ComboBox1->GetValue());
    selectedMonth = Choice1->GetSelection() + 1;
    selectedYear = wxAtoi(ComboBox2->GetValue());

    if (!IsDateValid(selectedDay, selectedMonth, selectedYear))
    {
        wxMessageBox(_("Nie ma takiej daty"), _("Bład :("), wxICON_ERROR | wxOK, this);
        return;
    }
    else{
        wxDateTime newDate(selectedDay, wxDateTime::Month(selectedMonth - 1), selectedYear);
        CalendarCtrl1->SetDate(newDate);
    }
}

void KalendarzDialog::OnButton3Click(wxCommandEvent& event)
{
    UpdateCalendarDate();
    UpdateCheckListBox();
    UpdateListBox();
    ListBox2->Clear();
    wxDateTime currentDate = CalendarCtrl1->GetDate();
    wxString dateString = currentDate.Format("%d-%m");

    bool holidaysFound = false;
    for (const auto& holiday : holidays)
    {
        wxString holidayDate = wxString::Format("%02d-%02d", holiday.second.day, holiday.second.month);

        if (dateString == holidayDate)
        {
            wxString displayString = wxString::Format("%s - %s", holiday.first, holiday.second.name);
            ListBox2->Append(displayString);
            selectedHolidays.push_back(holiday.second);
            holidaysFound = true;
        }
    }

    if (!holidaysFound)
    {
        ListBox2->Append(_("Nie ma świąt"));
    }
}

void KalendarzDialog::OnCalendarCtrl1Changed(wxCalendarEvent& event)
{
}

void KalendarzDialog::UpdateDay()
{
        wxCalendarEvent event;
    event.SetEventType(wxEVT_CALENDAR_SEL_CHANGED);
    event.SetId(CalendarCtrl1->GetId());
    int selectedDay = wxAtoi(ComboBox1->GetValue());
    int selectedMonth = Choice1->GetSelection() + 1;
    int selectedYear = wxAtoi(ComboBox2->GetValue());
    if (selectedDay != 0 && selectedMonth != 0 && selectedYear != 0) {
        wxDateTime selectedDate(selectedDay, static_cast<wxDateTime::Month>(selectedMonth - 1), selectedYear);
        event.SetDate(selectedDate);
    } else {
        event.SetDate(wxDateTime::Today());
    }
    OnCalendarCtrl1DblClicked(event);
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

//CHECKLIST BOX
void KalendarzDialog::AddEventToCheckListBox(const EventWithTime& eventWithTime)
{
    wxString displayString;
    if (eventWithTime.eventDateTime.GetHour() == 0 && eventWithTime.eventDateTime.GetMinute() == 0) {
        displayString = eventWithTime.eventName + wxT(" - ") + eventWithTime.eventDateTime.Format("%d-%m-%Y");
    } else {
        displayString = eventWithTime.eventName + wxT(" - ") + eventWithTime.eventDateTime.Format("%d-%m-%Y %H:%M");
    }
    CheckListBox1->Append(displayString);
}

void KalendarzDialog::OnButton1Click(wxCommandEvent& event)
{
    wxDialog* dialog = new wxDialog(this, wxID_ANY, wxT("Dodaj zdarzenie"), wxDefaultPosition, wxSize(300, 150));

    wxStaticText* labelEvent = new wxStaticText(dialog, wxID_ANY, wxT("Zdarzenie:"), wxPoint(10, 10), wxSize(80, 20));
    wxTextCtrl* textEvent = new wxTextCtrl(dialog, wxID_ANY, wxT(""), wxPoint(100, 10), wxSize(180, 20));

    wxStaticText* labelDateTime = new wxStaticText(dialog, wxID_ANY, wxT("Data i godzina(lub data):"), wxPoint(10, 40), wxSize(150, 20));
    wxTextCtrl* textDateTime = new wxTextCtrl(dialog, wxID_ANY, wxT(""), wxPoint(100, 40), wxSize(180, 20));
    textDateTime->SetHint(wxT("DD-MM-YYYY HH:MM"));

    wxButton* btnSave = new wxButton(dialog, wxID_ANY, wxT("Zapisz"), wxPoint(10, 80), wxSize(80, 25));
    wxButton* btnCancel = new wxButton(dialog, wxID_ANY, wxT("Anuluj"), wxPoint(100, 80), wxSize(80, 25));

    btnSave->Bind(wxEVT_BUTTON, [this, dialog, textEvent, textDateTime](wxCommandEvent& event) {
        wxString eventName = textEvent->GetValue();
        wxString eventDateTime = textDateTime->GetValue();

        if (eventName.IsEmpty() || eventDateTime.IsEmpty()) {
            wxMessageBox(_("Wprowadź wszystkie dane."), _("Błąd"), wxICON_ERROR | wxOK, this);
            return;
        }

        wxDateTime currentTime = wxDateTime::Now();
        wxDateTime enteredDateTime;

        if (enteredDateTime.ParseFormat(eventDateTime, "%d-%m-%Y %H:%M")) {
            if (enteredDateTime < currentTime) {
                wxMessageBox(_("Nieprawidłowa data. Wybierz datę w przyszłości."), _("Błąd :("), wxICON_ERROR | wxOK, this);
            } else {
                EventWithTime eventWithTime(eventName, enteredDateTime);
                eventsList.push_back(eventWithTime);
                dialog->EndModal(wxID_OK);
                UpdateDay();
            }
        }
        else if (enteredDateTime.ParseFormat(eventDateTime, "%d-%m-%Y")) {
            enteredDateTime.SetHour(0);
            enteredDateTime.SetMinute(0);

            EventWithTime eventWithTime(eventName, enteredDateTime);
            eventsList.push_back(eventWithTime);
            dialog->EndModal(wxID_OK);
            UpdateDay();
        } else {
            wxMessageBox(_("Format daty i godziny jest nieprawidłowy. Wprowadź format DD-MM-YYYY HH:MM lub DD-MM-YYYY."), _("Błąd :("), wxICON_ERROR | wxOK, this);
        }
    });

    btnCancel->Bind(wxEVT_BUTTON, [dialog](wxCommandEvent& event) {
        dialog->EndModal(wxID_CANCEL);
    });

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(labelEvent, 0, wxALL, 5);
    sizer->Add(textEvent, 0, wxALL, 5);
    sizer->Add(labelDateTime, 0, wxALL, 5);
    sizer->Add(textDateTime, 0, wxALL, 5);
    sizer->AddSpacer(10);
    sizer->Add(btnSave, 0, wxALL, 5);
    sizer->Add(btnCancel, 0, wxALL, 5);

    dialog->SetSizerAndFit(sizer);

    if (dialog->ShowModal() == wxID_OK) {
    }

    dialog->Destroy();
}


void KalendarzDialog::OnButton5Click(wxCommandEvent& event)
{
    wxDialog* dialog = new wxDialog(this, wxID_ANY, wxT("Wszystkie zdarzenia"), wxDefaultPosition, wxSize(350, 200), wxRESIZE_BORDER);

    std::sort(eventsList.begin(), eventsList.end(), [](const EventWithTime& a, const EventWithTime& b) {
    return a.eventDateTime > b.eventDateTime;
    });

    wxArrayString listBoxItems;
    for (const EventWithTime& event : eventsList) {
        wxString eventNameWithTime = event.eventName + wxT(" - ") + event.eventDateTime.Format("%d-%m-%Y %H:%M:%S");
        listBoxItems.Add(eventNameWithTime);
    }

    wxListBox* listBoxEvents = new wxListBox(dialog, wxID_ANY, wxDefaultPosition, wxSize(300, 120), listBoxItems, wxLB_SINGLE);

    wxButton* btnSort = new wxButton(dialog, wxID_ANY, wxT("Sortuj(wg dat)"), wxPoint(10, 130), wxSize(80, 25));
    btnSort->Bind(wxEVT_BUTTON, [this, listBoxEvents](wxCommandEvent& event) {
        std::sort(eventsList.begin(), eventsList.end(), [](const EventWithTime& a, const EventWithTime& b) {
            return a.eventDateTime < b.eventDateTime;
        });
        listBoxEvents->Freeze();
        listBoxEvents->Clear();
        for (const EventWithTime& event : eventsList) {
            wxString eventNameWithTime = event.eventName + wxT(" - ") + event.eventDateTime.Format("%d-%m-%Y %H:%M:%S");
            listBoxEvents->Append(eventNameWithTime);
        }
        listBoxEvents->Thaw();
    });

    wxButton* btnClose = new wxButton(dialog, wxID_ANY, wxT("Zamknij"), wxPoint(100, 130), wxSize(80, 25));
    btnClose->Bind(wxEVT_BUTTON, [dialog](wxCommandEvent& event) {
        dialog->EndModal(wxID_OK);
    });

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(listBoxEvents, 1, wxEXPAND | wxALL, 5);
    sizer->AddSpacer(10);
    sizer->Add(btnSort, 0, wxALL, 5);
    sizer->Add(btnClose, 0, wxALL, 5);
    dialog->SetSizerAndFit(sizer);
    dialog->ShowModal();
    dialog->Destroy();
}


void KalendarzDialog::UpdateCheckListBox()
{
    int selectedDay = wxAtoi(ComboBox1->GetValue());
    int selectedMonth = Choice1->GetSelection() + 1;
    int selectedYear = wxAtoi(ComboBox2->GetValue());
    CheckListBox1->Clear();

    for (const auto& event : eventsList)
    {
        if (event.eventDateTime.GetDay() == selectedDay &&
            event.eventDateTime.GetMonth() + 1 == selectedMonth &&
            event.eventDateTime.GetYear() == selectedYear)
        {
            wxString eventInfo;
            if (event.eventDateTime.GetHour() == 0 && event.eventDateTime.GetMinute() == 0)
            {
                eventInfo = event.eventName;
            }
            else
            {
                eventInfo = event.eventName + " " + event.eventDateTime.Format("%H:%M");
            }
            CheckListBox1->Append(eventInfo);
        }
    }
}

void KalendarzDialog::AddCheckListBoxItemsToVector() {
    for (unsigned int i = 0; i < CheckListBox1->GetCount(); ++i) {
        wxString itemText = CheckListBox1->GetString(i);
        size_t separatorPos = itemText.Find("-");

        if (separatorPos == wxString::npos) {
            continue;
        }
        wxString eventName = itemText.Mid(0, separatorPos).Strip(wxString::both);
        wxString dateTimeStr = itemText.Mid(separatorPos + 1).Strip(wxString::both);
        wxStringTokenizer tokenizer(dateTimeStr, "-");
        wxString day = tokenizer.GetNextToken();
        wxString month = tokenizer.GetNextToken();
        wxString year = tokenizer.GetNextToken();
        dateTimeStr = month + "-" + day + "-" + year;

        wxDateTime eventDateTime;
        if (!dateTimeStr.IsEmpty() && !dateTimeStr.Trim().IsEmpty()) {
            if (!eventDateTime.ParseDateTime(dateTimeStr) && !eventDateTime.ParseDate(dateTimeStr)) {
                wxMessageBox(_("Error parsing date-time: ") + dateTimeStr, _("Error"), wxOK | wxICON_ERROR, this);
                continue;
            }
            wxDateTime currentDateTime = wxDateTime::Now();
            if (eventDateTime.IsLaterThan(currentDateTime)) {
                EventWithTime eventWithTime(eventName, eventDateTime);
                eventsList.push_back(eventWithTime);
            }
        }
    }
}
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////


///////////////////////////////////////LIST BOX

void KalendarzDialog::OnButton2Click(wxCommandEvent& event)
{
    wxDialog* dialog = new wxDialog(this, wxID_ANY, wxT("Dodaj notatkę"), wxDefaultPosition, wxSize(300, 150));

    wxStaticText* labelEvent = new wxStaticText(dialog, wxID_ANY, wxT("Notatka:"), wxPoint(10, 10), wxSize(80, 20));
    wxTextCtrl* textEvent = new wxTextCtrl(dialog, wxID_ANY, wxT(""), wxPoint(100, 10), wxSize(180, 20));

    wxStaticText* labelDate = new wxStaticText(dialog, wxID_ANY, wxT("Data:"), wxPoint(10, 40), wxSize(80, 20));
    wxDatePickerCtrl* datePicker = new wxDatePickerCtrl(dialog, wxID_ANY, wxDefaultDateTime, wxPoint(100, 40), wxSize(200, 20), wxDP_DEFAULT);

    wxButton* btnSave = new wxButton(dialog, wxID_ANY, wxT("Zapisz"), wxPoint(10, 80), wxSize(80, 25));
    wxButton* btnCancel = new wxButton(dialog, wxID_ANY, wxT("Anuluj"), wxPoint(100, 80), wxSize(80, 25));

    btnSave->Bind(wxEVT_BUTTON, [this, dialog, textEvent, datePicker](wxCommandEvent& event) {
        wxString eventName = textEvent->GetValue();
        wxDateTime selectedDate = datePicker->GetValue();

        if (!selectedDate.IsValid()) {
            wxMessageBox(wxT("Nieprawidłowa data."), wxT("Błąd"), wxOK | wxICON_ERROR);
            return;
        }

        Note newNote(selectedDate, eventName);
        notes.push_back(newNote);
        dialog->EndModal(wxID_OK);
        UpdateDay();
    });

    btnCancel->Bind(wxEVT_BUTTON, [dialog](wxCommandEvent& event) {
        dialog->EndModal(wxID_CANCEL);
    });

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(labelEvent, 0, wxALL, 5);
    sizer->Add(textEvent, 0, wxALL, 5);
    sizer->Add(labelDate, 0, wxALL, 5);
    sizer->Add(datePicker, 0, wxALL, 5);
    sizer->AddSpacer(10);
    sizer->Add(btnSave, 0, wxALL, 5);
    sizer->Add(btnCancel, 0, wxALL, 5);

    dialog->SetSizerAndFit(sizer);

    if (dialog->ShowModal() == wxID_OK) {
    }
    dialog->Destroy();
}

void KalendarzDialog::OnButton6Click(wxCommandEvent& event)
{
    wxDialog* dialog = new wxDialog(this, wxID_ANY, wxT("Wszystkie notatki"), wxDefaultPosition, wxSize(500, 300), wxRESIZE_BORDER);


    wxListCtrl* listCtrlNotes = new wxListCtrl(dialog, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT);
    listCtrlNotes->InsertColumn(0, wxT("Notatka"), wxLIST_FORMAT_LEFT, 300);
    listCtrlNotes->InsertColumn(1, wxT("Data"), wxLIST_FORMAT_LEFT, 160);

    const std::vector<Note>& notes = GetNotes();

    for (size_t i = 0; i < notes.size(); ++i) {
        const Note& note = notes[i];
        wxString dateStr = note.GetFormattedDate();
        long index = listCtrlNotes->InsertItem(i, note.eventName);
        listCtrlNotes->SetItem(index, 1, dateStr);
    }

    wxButton* btnClose = new wxButton(dialog, wxID_ANY, wxT("Zamknij"), wxDefaultPosition, wxSize(80, 25));

    btnClose->Bind(wxEVT_BUTTON, [dialog](wxCommandEvent& event) {
        dialog->EndModal(wxID_OK);
    });

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(listCtrlNotes, 1, wxEXPAND | wxALL, 5);
    sizer->AddSpacer(10);
    sizer->Add(btnClose, 0, wxALL, 5);

    dialog->SetSizerAndFit(sizer);

    dialog->Bind(wxEVT_SIZE, [listCtrlNotes](wxSizeEvent& event) {

        wxSize size = event.GetSize();

        int column0Width = static_cast<int>(size.GetWidth() * 0.6);
        int column1Width = size.GetWidth() - column0Width;
        listCtrlNotes->SetColumnWidth(0, column0Width);
        listCtrlNotes->SetColumnWidth(1, column1Width);

        event.Skip();
    });

    dialog->ShowModal();
    dialog->Destroy();
}

std::vector<Note>& KalendarzDialog::GetNotes() {
    return notes;
}

void KalendarzDialog::UpdateListBox()
{
    int selectedDay = wxAtoi(ComboBox1->GetValue());
    int selectedMonth = Choice1->GetSelection() + 1;
    int selectedYear = wxAtoi(ComboBox2->GetValue());
    ListBox1->Clear();
    for (const Note& note : notes) {
        if (note.date.GetDay() == selectedDay &&
            note.date.GetMonth() + 1 == selectedMonth &&
            note.date.GetYear() == selectedYear) {
            wxString itemText = note.eventName;
            ListBox1->Append(itemText);
        }
    }
}

void KalendarzDialog::AddListBoxItemsToVector()
{
    auto ParseNoteFromString = [](const wxString& noteString) -> Note {
        size_t hyphenPos = noteString.find(wxT(" - "));
        if (hyphenPos == wxString::npos) {
            wxLogMessage("Invalid note format: %s", noteString);
            return Note(wxDateTime::Now(), wxEmptyString);
        }
        wxString eventName = noteString.substr(0, hyphenPos);
        wxString dateString = noteString.substr(hyphenPos + 3);
        wxDateTime date;
        if (date.ParseFormat(dateString, wxT("%d-%m-%Y"))) {
            return Note(date, eventName);
        } else {
            wxLogMessage("Failed to parse date from string: %s", dateString);
            return Note(wxDateTime::Now(), eventName);
        }
    };
    for (unsigned int i = 0; i < ListBox1->GetCount(); ++i) {
        wxString noteString = ListBox1->GetString(i);
        Note note = ParseNoteFromString(noteString);
        notes.push_back(note);
    }
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


////////////////USUWANIE

void KalendarzDialog::OnButton4Click(wxCommandEvent& event)
{
    int selectedIndexListBox = ListBox1->GetSelection();
    int selectedIndCheckListBox = CheckListBox1->GetSelection();
    if (selectedIndexListBox != wxNOT_FOUND && selectedIndCheckListBox != wxNOT_FOUND) {
        wxMessageDialog dialog(nullptr,
                               wxT("Nie jest możliwe usunięcie dwóch elementów jednocześnie."),
                               wxT("Błąd"),
                               wxOK | wxICON_ERROR);
        dialog.ShowModal();
    }
    else
    {
        if (selectedIndexListBox != wxNOT_FOUND) {
            wxString selectedItemText = ListBox1->GetString(selectedIndexListBox);
            auto it = std::remove_if(notes.begin(), notes.end(), [selectedItemText](const Note& note) {
                return note.eventName == selectedItemText;
            });
            notes.erase(it, notes.end());
            ListBox1->Delete(selectedIndexListBox);
        }

        if (selectedIndCheckListBox != wxNOT_FOUND) {
            wxString selectedCheckListBoxText = CheckListBox1->GetString(selectedIndCheckListBox);
            size_t pos = selectedCheckListBoxText.find_first_of(wxString::Format(wxT("0123456789")));
            wxString onlyText;
            if (pos != wxString::npos) {
                onlyText = selectedCheckListBoxText.SubString(0, pos - 2);
            } else {
                onlyText = selectedCheckListBoxText;
            }
            if(!(CheckListBox1->IsChecked(selectedIndCheckListBox)))
            {
                wxMessageDialog dialog(nullptr,
                                   wxT("Wydarzenie nie zostało ukończone. Czy na pewno chcesz je usunąć?"),
                                   wxT("Potwierdź usunięcie"),
                                   wxYES_NO |wxNO_DEFAULT| wxICON_QUESTION);
                dialog.SetYesNoLabels(wxGetTranslation("Nie"), wxGetTranslation("Tak"));
                int result = dialog.ShowModal();
                if (result != wxID_YES) {
                    auto it1 = std::remove_if(eventsList.begin(), eventsList.end(), [onlyText](const EventWithTime& eventsList) {
                        return eventsList.eventName == onlyText;
                    });
                    eventsList.erase(it1, eventsList.end());
                    CheckListBox1->Delete(selectedIndCheckListBox);
                }
                else {}
            }
            else
            {
               auto it1 = std::remove_if(eventsList.begin(), eventsList.end(), [onlyText](const EventWithTime& eventsList) {
                        return eventsList.eventName == onlyText;
                    });
                eventsList.erase(it1, eventsList.end());
                CheckListBox1->Delete(selectedIndCheckListBox);
            }
        }
    }
}


//USUWANIE ZA POMOCĄ PODWÓJNEGO KLIKU
void KalendarzDialog::OnCheckListBox1DClick(wxCommandEvent& event)
{
    int selectedIndCheckListBox = CheckListBox1->GetSelection();
    wxString selectedCheckListBoxText = CheckListBox1->GetString(selectedIndCheckListBox);
    size_t pos = selectedCheckListBoxText.find_first_of(wxString::Format(wxT("0123456789")));
    wxString onlyText;
    if (pos != wxString::npos) {
        onlyText = selectedCheckListBoxText.SubString(0, pos - 2);
    } else {
        onlyText = selectedCheckListBoxText;
    }
    if(!(CheckListBox1->IsChecked(selectedIndCheckListBox)))
    {
        wxMessageDialog dialog(nullptr,
                           wxT("Wydarzenie nie zostało ukończone. Czy na pewno chcesz je usunąć?"),
                           wxT("Potwierdź usunięcie"),
                           wxYES_NO |wxNO_DEFAULT| wxICON_QUESTION);
        dialog.SetYesNoLabels(wxGetTranslation("Nie"), wxGetTranslation("Tak")); //!
        int result = dialog.ShowModal();
        if (result != wxID_YES) {
            auto it1 = std::remove_if(eventsList.begin(), eventsList.end(), [onlyText](const EventWithTime& eventsList) {
                return eventsList.eventName == onlyText;
            });
            eventsList.erase(it1, eventsList.end());
            CheckListBox1->Delete(selectedIndCheckListBox);
        }
        else {}
    }
    else
    {
       auto it1 = std::remove_if(eventsList.begin(), eventsList.end(), [onlyText](const EventWithTime& eventsList) {
                return eventsList.eventName == onlyText;
            });
        eventsList.erase(it1, eventsList.end());
        CheckListBox1->Delete(selectedIndCheckListBox);
    }
}

void KalendarzDialog::OnListBox1DClick(wxCommandEvent& event)
{
    int selectedIndexListBox = ListBox1->GetSelection();
    wxString selectedItemText = ListBox1->GetString(selectedIndexListBox);
    auto it = std::remove_if(notes.begin(), notes.end(), [selectedItemText](const Note& note) {
        return note.eventName == selectedItemText;
    });
    notes.erase(it, notes.end());
    ListBox1->Delete(selectedIndexListBox);
}


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////




/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

////////////////WCZYTANIE I WYCZYTANIE PLIKU

void KalendarzDialog::SaveEventsToFile(const wxString& filename) {
    wxTextFile file;
    if (file.Create(filename)) {
        for (const Note& note : notes) {
            wxString line = wxString::Format("%s - %s",note.eventName, note.GetFormattedDate());
            file.AddLine(line);
        }

        file.AddLine(wxEmptyString);

        for (const EventWithTime& event : eventsList) {
            wxString line = wxString::Format("%s - %s|0",event.eventName, event.eventDateTime.Format("%d-%m-%Y %H:%M"));
            file.AddLine(line);
        }
        file.Write();
        file.Close();
    } else {
        wxMessageBox(wxT("Nie udało się otworzyć pliku do zapisu."), wxT("Błąd"), wxOK | wxICON_ERROR);
    }
}


void KalendarzDialog::OnButton8Click(wxCommandEvent& event)
{
    wxFileDialog saveFileDialog(this, _("Zapisz plik zdarzeń"), "", "", "Pliki tekstowe (*.txt)|*.txt", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    SaveEventsToFile(saveFileDialog.GetPath());
}

void KalendarzDialog::LoadEventsFromFile(const wxString& filename) {
    wxTextFile file;
    if (file.Open(filename)) {
        ListBox1->Clear();
        CheckListBox1->Clear();

        wxString line;
        bool isSeparatorReached = false;

        for (size_t i = 0; i < file.GetLineCount(); ++i) {
            line = file.GetLine(i);
            if (line.IsEmpty()) {
                isSeparatorReached = true;
                continue;
            }

            wxStringTokenizer tokenizer(line, "|");
            wxString eventName = tokenizer.GetNextToken();
            wxString isCheckedStr = tokenizer.GetNextToken();

            if (isSeparatorReached) {
                CheckListBox1->Append(eventName);
            } else {
                ListBox1->Append(eventName);
            }
        }

        file.Close();
///////////////////////

    AddCheckListBoxItemsToVector();
    AddListBoxItemsToVector();
    UpdateDay();

//////////////////////
    } else {
        wxMessageBox(wxT("Nie udało się otworzyć pliku do odczytu."), wxT("Błąd"), wxOK | wxICON_ERROR);
    }
}

void KalendarzDialog::OnButton7Click(wxCommandEvent& event)
{
     wxFileDialog openFileDialog(this, _("Wczytaj plik zdarzeń"), "", "", "Pliki tekstowe (*.txt)|*.txt", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    LoadEventsFromFile(openFileDialog.GetPath());
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////


/////////////ŚWIĄTA + INFO

void KalendarzDialog::InitHolidays(HolidayMap& holidays) {
    holidays[_("Dzień Sprzątania Biurka")] = {_("8 stycznia"), 8, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprzatania-biurka/"};
    holidays[_("Dzień Bałwana")] = {_("18 stycznia"), 18, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-balwana/"};
    holidays[_("Dzień Pingwinów")] = {_("20 stycznia"), 20, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pingwinow/"};
    holidays[_("Dzień Babci i Dzień Dziadka")] = {_("21 stycznia"), 21, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-babci-i-dzien-dziadka/"};
    holidays[_("Dzień Wiewiórki")] = {_("23 stycznia"), 23, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wiewiorki/"};
    holidays[_("Dzień Bez Opakowań Foliowych")] = {_("23 stycznia"), 23, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-opakowan-foliowych/"};
    holidays[_("Dzień Pamięci o Ofiarach Holocaustu")] = {_("27 stycznia"), 27, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pamieci-o-ofiarach-holocaustu/"};
    holidays[_("Dzień Zebry")] = {_("31 stycznia"), 31, 1, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zebry/"};
    holidays[_("Dzień bez oleju palmowego")] = {_("01 lutego"), 1, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-oleju-palmowego/"};
    holidays[_("Dzień Mokradeł")] = {_("02 lutego"), 2, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-mokradel/"};
    holidays[_("Międzynarodowy Dzień Zerowej Tolerancji dla Okaleczania Żeńskich Narządów Płciowych")] = {_("06 lutego"), 6, 2, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-zerowej-tolerancji-dla-okaleczania-zenskich-narzadow-plciowych/"};
    holidays[_("Dzień Kobiet i Dziewcząt w Nauce")] = {_("11 lutego"), 11, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kobiet-i-dziewczat-w-nauce/"};
    holidays[_("Dzień Dokarmiania Zwierzyny Leśnej")] = {_("11 lutego"), 11, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dokarmiania-zwierzyny-lesnej/"};
    holidays[_("Dzień Darwina")] = {_("12 lutego"), 12, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-darwina/"};
    holidays[_("Dzień Dzieci-Żołnierzy")] = {_("12 lutego"), 12, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dzieci-zolnierzy/"};
    holidays[_("Dzień Uzdrawiania Dźwiękiem")] = {_("14 lutego"), 14, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-uzdrawiania-dzwiekiem/"};
    holidays[_("Walentynki")] = {_("14 lutego"), 14, 2, "https://www.ekokalendarz.pl/kategoria/swieta/walentynki/"};
    holidays[_("Dzień Wielorybów")] = {_("15 lutego"), 15, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wielorybow/"};
    holidays[_("Tłusty czwartek")] = {_("16 lutego"), 16, 2, "https://www.ekokalendarz.pl/kategoria/swieta/tlusty-czwartek/"};
    holidays[_("Dzień Listonoszy i Doręczycieli Przesyłek Pocztowych")] = {_("16 lutego"), 16, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-listonoszy-i-doreczycieli/"};
    holidays[_("Dzień Kota")] = {_("17 lutego"), 17, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kota/"};
    holidays[_("Dzień Baterii")] = {_("18 lutego"), 18, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-baterii/"};
    holidays[_("Światowy Dzień Sprawiedliwości Społecznej")] = {_("20 lutego"), 20, 2, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-sprawiedliwosci-spolecznej/"};
    holidays[_("Dzień Języka Ojczystego")] = {_("21 lutego"), 21, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-jezyka-ojczystego/"};
    holidays[_("Dzień Sprzeciwu Wobec Reżimu Kolonialnego")] = {_("21 lutego"), 21, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprzeciwu-wobec-rezimu-kolonialnego/"};
    holidays[_("Dzień Organizacji Społecznych")] = {_("27 lutego"), 27, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-organizacji-spolecznych/"};
    holidays[_("Dzień Niedźwiedzia Polarnego")] = {_("27 lutego"), 27, 2, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-niedzwiedzia-polarnego/"};
    holidays[_("Dzień Walki Przeciw Zbrojeniom Atomowym")] = {_("01 marca"), 1, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-walki-przeciw-zbrojeniom-atomowym/"};
    holidays[_("Dzień Obrony Cywilnej")] = {_("01 marca"), 1, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-obrony-cywilnej/"};
    holidays[_("Dzień Wangari Maathai")] = {_("03 marca"), 3, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wangari-maathai/"};
    holidays[_("Dzień Środowiska Afrykańskiego")] = {_("03 marca"), 3, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-srodowiska-afrykanskiego/"};
    holidays[_("Europejski Dzień Równych Płac")] = {_("03 marca"), 3, 3, "https://www.ekokalendarz.pl/kategoria/swieta/europejski-dzien-rownych-plac/"};
    holidays[_("Dzień Dzikiej Przyrody")] = {_("03 marca"), 3, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dzikiej-przyrody/"};
    holidays[_("Dzień Kobiet")] = {_("08 marca"), 8, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kobiet/"};
    holidays[_("Dzień liczby Pi")] = {_("14 marca"), 14, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-liczby-pi/"};
    holidays[_("Światowy Dzień Praw Konsumenta")] = {_("15 marca"), 15, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-praw-konsumenta/"};
    holidays[_("Międzynarodowy Dzień Nowruz")] = {_("20 marca"), 20, 3, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-nowruz/"};
    holidays[_("Dzień bez Mięsa")] = {_("20 marca"), 20, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-miesa/"};
    holidays[_("Dzień Wróbla")] = {_("20 marca"), 20, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wrobla/"};
    holidays[_("Dzień Szczęścia")] = {_("20 marca"), 20, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-szczescia/"};
    holidays[_("Dzień Kolorowej Skarpetki")] = {_("21 marca"), 21, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kolorowej-skarpetki"};
    holidays[_("Dzień Wierzby")] = {_("21 marca"), 21, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wierzby/"};
    holidays[_("Światowy Dzień Poezji")] = {_("21 marca"), 21, 3, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-poezji/"};
    holidays[_("Dzień Walki z Rasizmem")] = {_("21 marca"), 21, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-walki-z-rasizmem/"};
    holidays[_("Pierwszy Dzień Wiosny")] = {_("21 marca"), 21, 3, "https://www.ekokalendarz.pl/kategoria/swieta/pierwszy-dzien-wiosny/"};
    holidays[_("Dzień Lasów")] = {_("21 marca"), 21, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-lasow/"};
    holidays[_("Światowy Dzień Wody")] = {_("22 marca"), 22, 3, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-wody/"};
    holidays[_("Dzień Meteorologii")] = {_("23 marca"), 23, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-meteorologii/"};
    holidays[_("Dzień Prawa do Prawdy dotyczącej Poważnych Naruszeń Praw Człowieka i Godności Ofiar")] = {_("24 marca"), 24, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-prawa-do-prawdy-dotyczacej-powaznych-naruszen-praw-czlowieka-i-godnosci-ofiar/"};
    holidays[_("Dzień Pamięci Ofiar Niewolnictwa i Transatlantyckiego Handlu Niewolnikami")] = {_("25 marca"), 25, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pamieci-ofiar-niewolnictwa-i-transatlantyckiego-handlu-niewolnikami/"};
    holidays[_("Międzynarodowy Dzień Teatru")] = {_("27 marca"), 27, 3, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-teatru/"};
    holidays[_("Dzień Chwastów")] = {_("28 marca"), 28, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-chwastow/"};
    holidays[_("Dzień Uznania dla Manatów")] = {_("29 marca"), 29, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-uznania-dla-manatow/"};
    holidays[_("Dzień Świadomości o Kleszczowym Zapaleniu Mózgu")] = {_("30 marca"), 30, 3, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-swiadomosci-o-kleszczowym-zapaleniu-mozgu/"};
    holidays[_("Dzień Ptaków")] = {_("01 kwietnia"), 1, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ptakow/"};
    holidays[_("Dzień Książki dla Dzieci")] = {_("02 kwietnia"), 2, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ksiazki-dla-dzieci/"};
    holidays[_("Dzień Zwierząt Bezdomnych")] = {_("04 kwietnia"), 4, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zwierzat-bezdomnych/"};
    holidays[_("Dzień Leśnika i Drzewiarza")] = {_("05 kwietnia"), 5, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-lesnika-drzewiarza/"};
    holidays[_("Światowy Dzień Zdrowia")] = {_("07 kwietnia"), 7, 4, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-zdrowia/"};
    holidays[_("Dzień Bobrów")] = {_("07 kwietnia"), 7, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bobrow/"};
    holidays[_("Wielkanoc")] = {_("09 kwietnia"), 9, 4, "https://www.ekokalendarz.pl/kategoria/swieta/wielkanoc/"};
    holidays[_("Światowy Dzień Czekolady")] = {_("12 kwietnia"), 12, 4, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-czekolady/"};
    holidays[_("Międzynarodowy Dzień Dzieci Ulicy")] = {_("12 kwietnia"), 12, 4, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-dzieci-ulicy/"};
    holidays[_("Dzień Gapienia się w Niebo")] = {_("14 kwietnia"), 14, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-gapienia-sie-w-niebo/"};
    holidays[_("Dzień Ochrony Słoni")] = {_("16 kwietnia"), 16, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ochrony-sloni/"};
    holidays[_("Międzynarodowy Dzień Ochrony Zabytków")] = {_("18 kwietnia"), 18, 4, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-ochrony-zabytkow-swieta/"};
    holidays[_("Dzień Wolnej Prasy")] = {_("20 kwietnia"), 20, 4, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-wolnej-prasy/"};
    holidays[_("Eid al-Fitr")] = {_("21 kwietnia"), 21, 4, "https://www.ekokalendarz.pl/kategoria/swieta/eid-al-fitr/"};
    holidays[_("Dzień Ziemi")] = {_("22 kwietnia"), 22, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ziemi/"};
    holidays[_("Światowy Dzień Książki")] = {_("23 kwietnia"), 23, 4, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-ksiazki/"};
    holidays[_("Dzień Zwierząt Laboratoryjnych")] = {_("24 kwietnia"), 24, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zwierzat-laboratoryjnych/"};
    holidays[_("Dzień Walki z Malarią")] = {_("25 kwietnia"), 25, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-walki-z-malaria/"};
    holidays[_("Dzień Świadomości Zagrożenia Hałasem")] = {_("25 kwietnia"), 25, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-swiadomosci-zagrozenia-halasem/"};
    holidays[_("Dzień Lekarzy Weterynarii")] = {_("27 kwietnia"), 27, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-lekarzy-weterynarii/"};
    holidays[_("Dzień Bezpieczeństwa i Ochrony Zdrowia w Pracy")] = {_("28 kwietnia"), 28, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bezpieczenstwa-i-ochrony-zdrowia-w-pracy/"};
    holidays[_("Dzień Sprzeciwu wobec Bicia Dzieci")] = {_("30 kwietnia"), 30, 4, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprzeciwu-wobec-bicia-dzieci/"};
    holidays[_("Święto Pracy")] = {_("01 maja"), 1, 5, "https://www.ekokalendarz.pl/kategoria/swieta/swieto-pracy/"};
    holidays[_("Dzień Tuńczyka")] = {_("02 maja"), 2, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-tunczyka/"};
    holidays[_("Dzień Bez Komputera")] = {_("03 maja"), 3, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-komputera/"};
    holidays[_("Międzynarodowy Dzień Strażaka")] = {_("04 maja"), 4, 5, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-strazaka/"};
    holidays[_("Dzień Walki z Dyskryminacją Osób Niepełnosprawnych")] = {_("05 maja"), 5, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-walki-z-dyskryminacja-osob-niepelnosprawnych/"};
    holidays[_("Dzień Bibliotek")] = {_("08 maja"), 8, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bibliotek/"};
    holidays[_("Dzień Czerwonego Krzyża")] = {_("08 maja"), 8, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-czerwonego-krzyza/"};
    holidays[_("Dzień Sprawiedliwego Handlu")] = {_("09 maja"), 9, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprawiedliwego-handlu/"};
    holidays[_("Dzień Drzewa Arganowego")] = {_("10 maja"), 10, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-drzewa-arganowego/"};
    holidays[_("Dzień bez śmiecenia")] = {_("11 maja"), 11, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-smiecenia/"};
    holidays[_("Dzień Ptaków Wędrownych")] = {_("12 maja"), 12, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ptakow-wedrownych/"};
    holidays[_("Międzynarodowy Dzień Rodzin")] = {_("15 maja"), 15, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-rodzin/"};
    holidays[_("Dzień Polskiej Niezapominajki")] = {_("15 maja"), 15, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-niezapominajki/"};
    holidays[_("Dzień siania dyni w miejscach publicznych")] = {_("16 maja"), 16, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-siania-dyni-w-miejscach-publicznych/"};
    holidays[_("Dzień Walki z Homofobią")] = {_("17 maja"), 17, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-walki-z-homofobia/"};
    holidays[_("Dzień Dobrych Uczynków")] = {_("19 maja"), 19, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dobrych-uczynkow/"};
    holidays[_("Światowy Dzień Pszczół")] = {_("20 maja"), 20, 5, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-pszczol/"};
    holidays[_("Światowy Dzień Kosmosu")] = {_("21 maja"), 21, 5, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-kosmosu/"};
    holidays[_("Dzień Różnorodności Kulturowej na rzecz Dialogu i Rozwoju")] = {_("21 maja"), 21, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-roznorodnosci-kulturowej-na-rzecz-dialogu-i-rozwoju/"};
    holidays[_("Dzień Różnorodności Biologicznej")] = {_("22 maja"), 22, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-roznorodnosci-biologicznej/"};
    holidays[_("Dzień Żółwia")] = {_("23 maja"), 23, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zolwia/"};
    holidays[_("Dzień Parków Narodowych")] = {_("24 maja"), 24, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-parkow-narodowych/"};
    holidays[_("Dzień Afryki")] = {_("25 maja"), 25, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-afryki/"};
    holidays[_("Dzień Matki")] = {_("26 maja"), 26, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-matki/"};
    holidays[_("Dzień Sąsiada")] = {_("27 maja"), 27, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sasiada/"};
    holidays[_("Dzień Świadomości Wydry")] = {_("29 maja"), 29, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-swiadomosci-wydry/"};
    holidays[_("Dzień Bociana Białego")] = {_("31 maja"), 31, 5, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bociana-bialego/"};
    holidays[_("Dzień Dziecka")] = {_("01 czerwca"), 1, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dziecka/"};
    holidays[_("BicycleDay")] = {_("Dzień Roweru"), 3, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-roweru/"};
    holidays[_("ChildrenVictimsDay")] = {_("Dzień Dzieci Będących Ofiarami Agresji"), 4, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dzieci-bedacych-ofiarami-agresji/"};
    holidays[_("EnvironmentProtectionDay")] = {_("Dzień Ochrony Środowiska"), 5, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ochrony-srodowiska/"};
    holidays[_("CircusWithoutAnimalsDay")] = {_("Dzień Cyrku bez Zwierząt"), 8, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-cyrku-bez-zwierzat/"};
    holidays[_("WorldOceansDay")] = {_("Dzień Oceanów"), 8, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-oceanow/"};
    holidays[_("WorldDollDay")] = {_("Dzień Lalki"), 8, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-lalki/"};
    holidays[_("ChildLabourOppositionDay")] = {_("Dzień Sprzeciwu Wobec Pracy Dzieci"), 12, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprzeciwu-wobec-pracy-dzieci/"};
    holidays[_("EmptyClassDay")] = {_("Dzień Pustej Klasy"), 14, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pustej-klasy/"};
    holidays[_("WindDay")] = {_("Dzień Wiatru"), 15, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wiatru/"};
    holidays[_("AfricanChildDay")] = {_("Dzień Dziecka Afrykańskiego"), 16, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dziecka-afrykanskiego/"};
    holidays[_("CombatDesertificationDay")] = {_("Dzień Przeciwdziałania Pustynnieniu i Suszy"), 17, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-przeciwdzialania-pustynnieniu-i-suszy/"};
    holidays[_("GMOProtestDay")] = {_("Dzień Protestu Przeciwko GMO"), 18, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-protestu-przeciwko-gmo/"};
    holidays[_("LazyStrollsDay")] = {_("Dzień Leniwych Spacerów"), 19, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-leniwych-spacerow/"};
    holidays[_("WorldRefugeeDay")] = {_("Światowy Dzień Uchodźcy"), 20, 6, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-uchodzcy/"};
    holidays[_("WorldGiraffeDay")] = {_("Światowy Dzień Żyrafy"), 21, 6, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-zyrafy/"};
    holidays[_("MidsummerNight")] = {_("Noc Kupały"), 21, 6, "https://www.ekokalendarz.pl/kategoria/swieta/noc-kupaly/"};
    holidays[_("FatherDay")] = {_("Dzień Ojca"), 23, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ojca/"};
    holidays[_("WidowsDay")] = {_("Dzien Wdów"), 23, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wdow/"};
    holidays[_("TortureVictimsHelpDay")] = {_("Dzień Pomocy Ofiarom Tortur"), 26, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pomocy-ofiarom-tortur/"};
    holidays[_("FishingDay")] = {_("Dzień Rybołówstwa"), 27, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-rybolowstwa/"};
    holidays[_("CabbageWhiteButterflyDay")] = {_("Dzień Motyla Kapustnika"), 30, 6, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-motyla-kapustnika/"};
    holidays[_("ArchitectureDay")] = {_("Dzień Architektury"), 1, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-architektury/"};
    holidays[_("DogDay")] = {_("Dzień Psa"), 1, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-psa/"};
    holidays[_("ParkOutingsDay")] = {_("Dzień Wypadów do Parku"), 4, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wypadow-do-parku/"};
    holidays[_("WorldPopulationDay")] = {_("Światowy Dzień Ludności"), 11, 7, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-ludnosci/"};
    holidays[_("NoMobilePhoneDay")] = {_("Dzień bez Telefonu Komórkowego"), 15, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-telefonu-komorkowego/"};
    holidays[_("ListeningDay")] = {_("Dzień Słuchania"), 18, 7, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-sluchania/"};
    holidays[_("NelsonMandelaDay")] = {_("Dzień Nelsona Mandeli"), 18, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-nelsona-mandeli/"};
    holidays[_("MangroveEcosystemsProtectionDay")] = {_("Dzień Ochrony Ekosystemów Namorzynowych"), 26, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ochrony-ekosystemow-namorzynowych/"};
    holidays[_("TigerDay")] = {_("Dzień Tygrysa"), 29, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-tygrysa/"};
    holidays[_("EcologicalDebtDay")] = {_("Dzień Długu Ekologicznego"), 29, 7, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-dlugu-ekologicznego/"};
    holidays[_("WorldBeeDay")] = {_("Wielki Dzień Pszczół"), 8, 8, "https://www.ekokalendarz.pl/kategoria/swieta/wielki-dzien-pszczol/"};
    holidays[_("IndigenousPeoplesDay")] = {_("Dzień Ludności Rdzennej"), 9, 8, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ludnosci-rdzennej/"};
    holidays[_("HumanitarianAssistanceDay")] = {_("Dzień Pomocy Humanitarnej"), 19, 8, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pomocy-humanitarnej/"};
    holidays[_("MosquitoDay")] = {_("Światowy Dzień Komara"), 20, 8, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-komara/"};
    holidays[_("SlaveryAbolitionMemorialDay")] = {_("Międzynarodowy Dzień Pamięci o Handlu Niewolnikami i jego Zniesieniu"), 23, 8, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-pamieci-o-handlu-niewolnikami-i-jego-zniesieniu/"};
    holidays[_("InternationalBatNight")] = {_("Międzynarodowa Noc Nietoperzy"), 25, 8, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowa-noc-nietoperzy/"};
    holidays[_("AntiNuclearTestingDay")] = {_("Dzień Sprzeciwu Wobec Prób Jądrowych"), 29, 8, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprzeciwu-wobec-prob-jadrowych/"};
    holidays[_("InternationalLiteracyDay")] = {_("Międzynarodowy Dzień Alfabetyzacji"), 8, 9, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-alfabetyzacji/"};
    holidays[_("ElkDay")] = {_("Dzień Łosia"), 11, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-losia/"};
    holidays[_("SouthSouthCooperationDay")] = {_("Dzień na rzecz Współpracy Południe–Południe"), 12, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-na-rzecz-wspolpracy-poludnie-poludnie/"};
    holidays[_("DemocracyDay")] = {_("Dzień Demokracji"), 15, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-demokracji/"};
    holidays[_("SolidarityDayWithGarmentWorkersInCambodia")] = {_("Dzień Solidarności z pracownicami fabryk odzieżowych w Kambodży"), 17, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-solidarnosci-z-pracownicami-fabryk-odziezowych-w-kambodzy/"};
    holidays[_("ParkingDay")] = {_("Park(ing) Day"), 19, 9, "https://www.ekokalendarz.pl/kategoria/swieta/parking-day/"};
    holidays[_("WildlifeFloraAndHabitatsDay")] = {_("Dzień Dzikiej Fauny, Flory i Naturalnych Siedlisk"), 19, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien_dzikiej_fauny_i_flory/"};
    holidays[_("PeaceDay")] = {_("Dzień Pokoju"), 21, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pokoju/"};
    holidays[_("HarvestFestival")] = {_("Dożynki"), 22, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dozynki-swieta/"};
    holidays[_("CarFreeDay")] = {_("Dzień Bez Samochodu"), 22, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien_bez_samochodu/"};
    holidays[_("WorldTourismDay")] = {_("Światowy Dzień Turystyki"), 27, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-turystyki/"};
    holidays[_("RiverDay")] = {_("Dzień Rzek"), 27, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-rzek/"};
    holidays[_("WorldSeasDay")] = {_("Światowy Dzień Mórz"), 28, 9, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-morz/"};
    holidays[_("SeasDay")] = {_("Dzień Mórz"), 28, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-morz/"};
    holidays[_("CourierAndTransporterDay")] = {_("Dzień Kuriera i Przewoźnika"), 29, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien_kuriera/"};
    holidays[_("FoodWasteAwarenessDay")] = {_("Dzień Świadomości o Marnowaniu Żywności"), 29, 9, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-swiadomosci-o-marnowaniu-zywnosci/"};
    holidays[_("InternationalCoffeeDay")] = {_("Międzynarodowy Dzień Kawy"), 29, 9, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-kawy/"};
    holidays[_("VegetarianismDay")] = {_("Dzień Wegetarianizmu"), 1, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wegetarianizmu/"};
    holidays[_("ElderlyPersonsDay")] = {_("Dzień Osób Starszych"), 1, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-osob-starszych/"};
    holidays[_("EmpathyDay")] = {_("Dzień Empatii"), 2, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-empatii/"};
    holidays[_("FarmAnimalDay")] = {_("Dzień Zwierząt Hodowlanych"), 2, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zwierzat-hodowlanych/"};
    holidays[_("InternationalNonViolenceDay")] = {_("Międzynarodowy Dzień bez Przemocy"), 2, 10, "https://www.ekokalendarz.pl/kategoria/swieta/miedzynarodowy-dzien-bez-przemocy/"};
    holidays[_("WorldAnimalDay")] = {_("Światowy Dzień Zwierząt"), 4, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zwierzat/"};
    holidays[_("WorldHabitatDay")] = {_("Światowy Dzień Mieszkalnictwa"), 6, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-mieszkalnictwa/"};
    holidays[_("FairWagesDay")] = {_("Dzień Godnej Płacy"), 7, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-godnej-placy/"};
    holidays[_("TreeDay")] = {_("Święto Drzewa"), 10, 10, "https://www.ekokalendarz.pl/kategoria/swieta/swieto-drzewa/"};
    holidays[_("DeathPenaltyOppositionDay")] = {_("Dzień Sprzeciwu Wobec Kary Śmierci"), 10, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-sprzeciwu-wobec-kary-smierci/"};
    holidays[_("ReducingDisasterImpactDay")] = {_("Dzień Zmniejszania Skutków Klęsk Żywiołowych"), 13, 10, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-zmniejszania-skutkow-klesk-zywiolowych/"};
    holidays[_("EducationDay")] = {_("Dzień Edukacji Narodowej"), 14, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-edukacji-narodowej/"};
    holidays[_("HandwashingDay")] = {_("Dzień Mycia Rąk"), 15, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-mycia-rak/"};
    holidays[_("RuralWomenDay")] = {_("Dzień Kobiet Wiejskich"), 15, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kobiet-wiejskich/"};
    holidays[_("WorldFoodDay")] = {_("Światowy Dzień Żywności"), 16, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zywnosci/"};
    holidays[_("AntiPovertyDay")] = {_("Dzień Walki z Ubóstwem"), 17, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-walki-z-ubostwem/"};
    holidays[_("NZDay")] = {_("Dzień NZ"), 24, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-nz/"};
    holidays[_("DevelopmentInformationDay")] = {_("Dzień Informacji o Rozwoju"), 24, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-informacji-o-rozwoju/"};
    holidays[_("MongrelDay")] = {_("Dzień Kundelka"), 24, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kundelka/"};
    holidays[_("NervousBreakDay")] = {_("Dzień Odpoczynku dla Zszarganych Nerwów"), 28, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-odpoczynku-dla-nerwow/"};
    holidays[_("CityDay")] = {_("Dzień Miast"), 31, 10, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-miast/"};
    holidays[_("WorldVeganDay")] = {_("Dzień Weganizmu"), 1, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien_weganizmu/"};
    holidays[_("AllSaintsDay")] = {_("Dzień Zaduszny"), 2, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zaduszny/"};
    holidays[_("EnvironmentalExploitationPreventionDay")] = {_("Dzień Zapobiegania Wyzyskowi Środowiska Naturalnego podczas Wojen"), 6, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zapobiegania-wyzyskowi-srodowiska-naturalnego-podczas-wojen/"};
    holidays[_("HedgehogDay")] = {_("Dzień Jeża"), 10, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-jeza/"};
    holidays[_("ScienceDayForPeaceAndDevelopment")] = {_("Dzień Nauki dla Pokoju i Rozwoju"), 10, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-nauki-dla-pokoju-i-rozwoju/"};
    holidays[_("CleanAirDay")] = {_("Dzień Czystego Powietrza"), 14, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-czystego-powietrza/"};
    holidays[_("ToleranceDay")] = {_("Dzień Tolerancji"), 16, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-tolerancji/"};
    holidays[_("GlobalEducationWeek")] = {_("Tydzień Edukacji Globalnej"), 17, 11, "https://www.ekokalendarz.pl/kategoria/swieta/teg-swieta/"};
    holidays[_("AntibioticAwarenessDay")] = {_("Dzień Wiedzy o Antybiotykach"), 18, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wiedzy-o-antybiotykach/"};
    holidays[_("ToiletDay")] = {_("Dzień Toalet"), 19, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-toalet/"};
    holidays[_("PreventionViolenceAgainstChildrenDay")] = {_("Dzień Zapobiegania Przemocy Wobec Dzieci"), 19, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zapobiegania-przemocy-wobec-dzieci/"};
    holidays[_("ChildrensRightsDay")] = {_("Dzień Praw Dziecka"), 20, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-praw-dziecka/"};
    holidays[_("IndustrializationAfricaDay")] = {_("Dzień Uprzemysłowienia Afryki"), 20, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-uprzemyslowienia-afryki/"};
    holidays[_("FriendshipDay")] = {_("Dzień Życzliwości"), 21, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-zyczliwosci/"};
    holidays[_("CatherinesDay")] = {_("Katarzynki"), 24, 11, "https://www.ekokalendarz.pl/kategoria/swieta/katarzynki/"};
    holidays[_("TeddyBearDay")] = {_("Dzień Pluszowego Misia"), 25, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-pluszowego-misia/"};
    holidays[_("RailwayTramworkerDay")] = {_("Dzień Kolejarza i Tramwajarza"), 25, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-kolejarza-i-tramwajarza/"};
    holidays[_("FurFreeDay")] = {_("Dzień bez Futra"), 25, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-futra/"};
    holidays[_("BuyNothingDay")] = {_("Dzień bez kupowania"), 28, 11, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-bez-kupowania/"};
    holidays[_("StAndrewsDay")] = {_("Andrzejki"), 29, 11, "https://www.ekokalendarz.pl/kategoria/swieta/andrzejki-swieta/"};
    holidays[_("WorldAIDSDay")] = {_("Światowy Dzień Walki z AIDS"), 1, 12, "https://www.ekokalendarz.pl/kategoria/swieta/swiatowy-dzien-walki-z-aids/"};
    holidays[_("AbolitionSlaveryDay")] = {_("Dzień Upamiętniający Zniesienie Niewolnictwa"), 2, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-upamietniajacy-zniesienie-niewolnictwa/"};
    holidays[_("InternationalDayDisabledPersons")] = {_("Dzień Osób Niepełnosprawnych"), 3, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-osob-niepelnosprawnych/"};
    holidays[_("Barborka")] = {_("Barbórka"), 4, 12, "https://www.ekokalendarz.pl/kategoria/swieta/barborka/"};
    holidays[_("SoilDay")] = {_("Dzień Gleb"), 5, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-gleb/"};
    holidays[_("VolunteerDay")] = {_("Dzień Wolontariusza"), 5, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-wolontariusza/"};
    holidays[_("StNicholasDay")] = {_("Mikołajki"), 6, 12, "https://www.ekokalendarz.pl/kategoria/swieta/mikolajki/"};
    holidays[_("KamishibaiTheatreDay")] = {_("Dzień Teatrzyku Kamishibai"), 7, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-teatrzyku-kamishibai/"};
    holidays[_("CivilAviationDay")] = {_("Dzień Lotnictwa Cywilnego"), 7, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-lotnictwa-cywilnego/"};
    holidays[_("HumanRightsDay")] = {_("Dzień Praw Człowieka"), 10, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-praw-czlowieka/"};
    holidays[_("MountainAreasDay")] = {_("Dzień Terenów Górskich"), 11, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-terenow-gorskich/"};
    holidays[_("MonkeyDay")] = {_("Dzień Małpy"), 14, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-malpy/"};
    holidays[_("Hanukkah")] = {_("Chanuka"), 18, 12, "https://www.ekokalendarz.pl/kategoria/swieta/chanuka/"};
    holidays[_("FishDay")] = {_("Dzień Ryby"), 20, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-ryby/"};
    holidays[_("SolidarityDay")] = {_("Dzień Solidarności"), 20, 12, "https://www.ekokalendarz.pl/kategoria/swieta/dzien-solidarnosci/"};
    holidays[_("ChristmasEve")] = {_("Wigilia"), 24, 12, "https://www.ekokalendarz.pl/kategoria/swieta/wigilia/"};
    holidays[_("NewYearsEve")] = {_("Sylwester"), 31, 12, "https://www.ekokalendarz.pl/kategoria/swieta/sylwester/"};
}


void KalendarzDialog::OnButton9Click(wxCommandEvent& event)
{
    if (selectedHolidays.empty())
    {
        wxMessageBox(_("Brak świąt do wyświetlenia"), _("Błąd"), wxICON_ERROR | wxOK, this);
        return;
    }

    for (const auto& holiday : selectedHolidays)
    {
        wxString url = wxString::FromUTF8(holiday.href.c_str());
        wxLaunchDefaultBrowser(url);
    }
}

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
