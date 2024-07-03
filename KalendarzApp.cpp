/***************************************************************
 * Name:      KalendarzApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-12-29
 * Copyright:  ()
 * License:
 **************************************************************/

#include "KalendarzApp.h"

//(*AppHeaders
#include "KalendarzMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(KalendarzApp);

bool KalendarzApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	KalendarzDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
