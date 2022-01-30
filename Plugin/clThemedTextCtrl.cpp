#include "clThemedTextCtrl.hpp"

#include "ColoursAndFontsManager.h"
#include "clSystemSettings.h"
#include "event_notifier.h"
#include "globals.h"

#include <wx/bitmap.h>
#include <wx/dcgraph.h>
#include <wx/dcmemory.h>

clThemedTextCtrl::clThemedTextCtrl(wxWindow* parent, wxWindowID id, const wxString& value, const wxPoint& pos,
                                   const wxSize& size, long style)
    : wxStyledTextCtrl(parent, id, pos, size, wxBORDER_NONE)
{
    wxUnusedVar(style);
    ApplySettings();
    SetModEventMask(wxSTC_MOD_DELETETEXT | wxSTC_MOD_INSERTTEXT);

    // Bind(wxEVT_STC_CHARADDED, &clThemedTextCtrl::OnAddChar, this);
    Bind(wxEVT_KEY_DOWN, &clThemedTextCtrl::OnKeyDown, this);
    Bind(wxEVT_STC_MODIFIED, &clThemedTextCtrl::OnChange, this);
    EventNotifier::Get()->Bind(wxEVT_SYS_COLOURS_CHANGED, &clThemedTextCtrl::OnSysColours, this);
}

clThemedTextCtrl::~clThemedTextCtrl()
{
    // Unbind(wxEVT_STC_CHARADDED, &clThemedTextCtrl::OnAddChar, this);
    Unbind(wxEVT_KEY_DOWN, &clThemedTextCtrl::OnKeyDown, this);
    Unbind(wxEVT_STC_MODIFIED, &clThemedTextCtrl::OnChange, this);
    EventNotifier::Get()->Unbind(wxEVT_SYS_COLOURS_CHANGED, &clThemedTextCtrl::OnSysColours, this);
}

void clThemedTextCtrl::OnKeyDown(wxKeyEvent& event)
{
    event.Skip();
    if(event.GetKeyCode() == WXK_RETURN || event.GetKeyCode() == WXK_NUMPAD_ENTER) {
        event.Skip(false);
        wxCommandEvent text_enter(wxEVT_COMMAND_TEXT_ENTER);
        text_enter.SetEventObject(this);
        GetEventHandler()->AddPendingEvent(text_enter);
    }
}

void clThemedTextCtrl::OnAddChar(wxStyledTextEvent& event)
{
    event.Skip();
    wxCommandEvent event_text(wxEVT_COMMAND_TEXT_UPDATED);
    event_text.SetEventObject(this);
    GetEventHandler()->AddPendingEvent(event_text);
}

void clThemedTextCtrl::OnChange(wxStyledTextEvent& event)
{
    event.Skip();
    if(event.GetModificationType() & (wxSTC_MOD_DELETETEXT | wxSTC_MOD_INSERTTEXT)) {
        wxCommandEvent text_enter(wxEVT_COMMAND_TEXT_UPDATED);
        text_enter.SetEventObject(this);
        GetEventHandler()->AddPendingEvent(text_enter);
    }
}

void clThemedTextCtrl::OnSysColours(clCommandEvent& event)
{
    event.Skip();
    ApplySettings();
}

void clThemedTextCtrl::ApplySettings()
{
    auto lexer = ColoursAndFontsManager::Get().GetLexer("text");
    lexer->Apply(this);

    wxBitmap bmp(1, 1);
    wxMemoryDC _memDC(bmp);
    wxGCDC gcdc(_memDC);
    gcdc.SetFont(lexer->GetFontForSyle(0, this));
    wxRect rect = gcdc.GetTextExtent("Tp");
    rect.Inflate(1);
    SetSizeHints(wxNOT_FOUND, rect.GetHeight()); // use the height of the button
    ::clRecalculateSTCHScrollBar(this);
}