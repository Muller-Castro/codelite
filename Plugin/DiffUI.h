//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: DiffUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CODELITE_PLUGIN_DIFFUI_BASE_CLASSES_H
#define _CODELITE_PLUGIN_DIFFUI_BASE_CLASSES_H

#include "clThemedListCtrl.h"
#include "clToolBar.h"

#include <wx/artprov.h>
#include <wx/button.h>
#include <wx/dataview.h>
#include <wx/dialog.h>
#include <wx/filepicker.h>
#include <wx/iconbndl.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/toolbar.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/xrc/xmlres.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif

class DiffSelectFoldersBaseDlg : public wxDialog
{
protected:
    wxPanel* m_panel46;
    wxStaticText* m_staticText54;
    wxDirPickerCtrl* m_dirPickerLeft;
    wxDirPickerCtrl* m_dirPickerRight;
    wxStdDialogButtonSizer* m_stdBtnSizer40;
    wxButton* m_buttonOK;
    wxButton* m_buttonCancel;

protected:
    virtual void OnOKUI(wxUpdateUIEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText54() { return m_staticText54; }
    wxDirPickerCtrl* GetDirPickerLeft() { return m_dirPickerLeft; }
    wxDirPickerCtrl* GetDirPickerRight() { return m_dirPickerRight; }
    wxPanel* GetPanel46() { return m_panel46; }
    DiffSelectFoldersBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Select Folder"),
                             const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300),
                             long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DiffSelectFoldersBaseDlg();
};

class DiffFoldersBaseDlg : public wxDialog
{
protected:
    wxPanel* m_panel4;
    clToolBar* m_toolbar;
    clThemedListCtrl* m_dvListCtrl;

protected:
    virtual void OnItemActivated(wxDataViewEvent& event) { event.Skip(); }
    virtual void OnItemContextMenu(wxDataViewEvent& event) { event.Skip(); }

public:
    clToolBar* GetToolbar() { return m_toolbar; }
    clThemedListCtrl* GetDvListCtrl() { return m_dvListCtrl; }
    wxPanel* GetPanel4() { return m_panel4; }
    DiffFoldersBaseDlg(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Diff Folders"),
                       const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300),
                       long style = wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER);
    virtual ~DiffFoldersBaseDlg();
};

#endif
