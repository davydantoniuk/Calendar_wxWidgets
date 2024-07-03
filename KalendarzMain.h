/***************************************************************
 * Name:      KalendarzMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-12-29
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef KALENDARZMAIN_H
#define KALENDARZMAIN_H
#include <map>
#include <string>
#include <vector>
#include <wx/string.h>
#include <wx/datetime.h>
#include <wx/listctrl.h>
#include "EventWithTime.h"
#include "Note.h"
//(*Headers(KalendarzDialog)
#include <wx/button.h>
#include <wx/calctrl.h>
#include <wx/checklst.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/timer.h>
//*)
class KalendarzDialog: public wxDialog
{
    public:
        struct HolidayInfo {
        wxString name;
        int day;
        int month;
        std::string href;
        };
        using HolidayMap = std::map<wxString, HolidayInfo>;
        KalendarzDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~KalendarzDialog();
        void SaveEventsToFile(const wxString& filename);
        void LoadEventsFromFile(const wxString& filename);
        void InitComboBoxes();
        void UpdateDaysList();
        void UpdateCalendarDate();
        void AddEventToCheckListBox(const EventWithTime& eventWithTime);
        void InitHolidays(HolidayMap& holidays);
        void OnCalendarSelect(wxCalendarEvent& event);
        void InitCalendar();
        bool IsDateValid(int day, int month, int year);
        void UpdateDay();
        void AddCheckListBoxItemsToVector();
        void UpdateCheckListBox();
        std::vector<Note>& GetNotes();
        void UpdateListBox();
        void AddListBoxItemsToVector();
    private:

        //(*Handlers(KalendarzDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnTimer1Trigger(wxTimerEvent& event);
        void OnComboBox1Selected(wxCommandEvent& event);
        void OnChoice1Select1(wxCommandEvent& event);
        void OnComboBox2Selected(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnCalendarCtrl1Changed(wxCalendarEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        void OnButton7Click(wxCommandEvent& event);
        void OnButton8Click(wxCommandEvent& event);
        void OnCalendarCtrl1DblClicked(wxCalendarEvent& event);
        void OnButton9Click(wxCommandEvent& event);
        void OnCheckListBox1DClick(wxCommandEvent& event);
        void OnListBox1DClick(wxCommandEvent& event);
        //*)

        //(*Identifiers(KalendarzDialog)
        static const long ID_COMBOBOX1;
        static const long ID_CHOICE1;
        static const long ID_COMBOBOX2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON9;
        static const long ID_CALENDARCTRL1;
        static const long ID_CHECKLISTBOX1;
        static const long ID_LISTBOX1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_BUTTON7;
        static const long ID_BUTTON8;
        static const long ID_BUTTON4;
        static const long ID_STATICTEXT1;
        static const long ID_LISTBOX2;
        static const long ID_TIMER1;
        //*)

        //(*Declarations(KalendarzDialog)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxButton* Button6;
        wxButton* Button7;
        wxButton* Button8;
        wxButton* Button9;
        wxCalendarCtrl* CalendarCtrl1;
        wxCheckListBox* CheckListBox1;
        wxChoice* Choice1;
        wxComboBox* ComboBox1;
        wxComboBox* ComboBox2;
        wxListBox* ListBox1;
        wxListBox* ListBox2;
        wxStaticText* StaticText1;
        wxTimer Timer1;
        //*)
    int selectedDay;
    int selectedMonth;
    int selectedYear;
    wxString selectedHolidayURL;
    HolidayMap holidays;
    std::vector<HolidayInfo> selectedHolidays;
    std::vector<EventWithTime> eventsList;
    std::vector<Note> notes;
    DECLARE_EVENT_TABLE()
};

#endif // KALENDARZMAIN_H
