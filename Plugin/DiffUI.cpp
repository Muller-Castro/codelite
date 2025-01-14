//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: DiffUI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "DiffUI.h"

// Declare the bitmap loading function
extern void wxCrafterIlcShpInitBitmapResources();

static bool bBitmapLoaded = false;

DiffSelectFoldersBaseDlg::DiffSelectFoldersBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title,
                                                   const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterIlcShpInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer38 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer38);

    m_panel46 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer38->Add(m_panel46, 1, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer48 = new wxBoxSizer(wxVERTICAL);
    m_panel46->SetSizer(boxSizer48);

    m_staticText54 = new wxStaticText(m_panel46, wxID_ANY, _("Select folders for comparison:"), wxDefaultPosition,
                                      wxDLG_UNIT(m_panel46, wxSize(-1, -1)), 0);

    boxSizer48->Add(m_staticText54, 0, wxALL, WXC_FROM_DIP(5));

    m_dirPickerLeft = new wxDirPickerCtrl(m_panel46, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition,
                                          wxDLG_UNIT(m_panel46, wxSize(-1, -1)),
                                          wxDIRP_SMALL | wxDIRP_DEFAULT_STYLE | wxDIRP_USE_TEXTCTRL);

    boxSizer48->Add(m_dirPickerLeft, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_dirPickerRight = new wxDirPickerCtrl(m_panel46, wxID_ANY, wxEmptyString, _("Select a folder"), wxDefaultPosition,
                                           wxDLG_UNIT(m_panel46, wxSize(-1, -1)),
                                           wxDIRP_SMALL | wxDIRP_DEFAULT_STYLE | wxDIRP_USE_TEXTCTRL);

    boxSizer48->Add(m_dirPickerRight, 0, wxALL | wxEXPAND, WXC_FROM_DIP(5));

    m_stdBtnSizer40 = new wxStdDialogButtonSizer();

    boxSizer38->Add(m_stdBtnSizer40, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, WXC_FROM_DIP(5));

    m_buttonOK = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_buttonOK->SetDefault();
    m_stdBtnSizer40->AddButton(m_buttonOK);

    m_buttonCancel = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), 0);
    m_stdBtnSizer40->AddButton(m_buttonCancel);
    m_stdBtnSizer40->Realize();

    SetName(wxT("DiffSelectFoldersBaseDlg"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_buttonOK->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(DiffSelectFoldersBaseDlg::OnOKUI), NULL, this);
}

DiffSelectFoldersBaseDlg::~DiffSelectFoldersBaseDlg()
{
    m_buttonOK->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(DiffSelectFoldersBaseDlg::OnOKUI), NULL, this);
}

DiffFoldersBaseDlg::DiffFoldersBaseDlg(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos,
                                       const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if(!bBitmapLoaded) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafterIlcShpInitBitmapResources();
        bBitmapLoaded = true;
    }

    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);

    m_panel4 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1, -1)), wxTAB_TRAVERSAL);

    boxSizer2->Add(m_panel4, 1, wxEXPAND, WXC_FROM_DIP(5));

    wxBoxSizer* boxSizer6 = new wxBoxSizer(wxVERTICAL);
    m_panel4->SetSizer(boxSizer6);

    m_toolbar = new clToolBar(m_panel4, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel4, wxSize(-1, -1)), wxTB_FLAT);
    m_toolbar->SetToolBitmapSize(wxSize(16, 16));

    boxSizer6->Add(m_toolbar, 0, wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl = new clThemedListCtrl(m_panel4, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel4, wxSize(500, 400)),
                                        wxDV_ROW_LINES | wxDV_SINGLE);

    boxSizer6->Add(m_dvListCtrl, 1, wxEXPAND, WXC_FROM_DIP(5));

    m_dvListCtrl->AppendIconTextColumn(_("Left"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                       wxDATAVIEW_COL_RESIZABLE);
    m_dvListCtrl->AppendIconTextColumn(_("Right"), wxDATAVIEW_CELL_INERT, WXC_FROM_DIP(-2), wxALIGN_LEFT,
                                       wxDATAVIEW_COL_RESIZABLE);

    SetName(wxT("DiffFoldersBaseDlg"));
    SetSize(wxDLG_UNIT(this, wxSize(500, 300)));
    if(GetSizer()) {
        GetSizer()->Fit(this);
    }
    if(GetParent()) {
        CentreOnParent(wxBOTH);
    } else {
        CentreOnScreen(wxBOTH);
    }
#if wxVERSION_NUMBER >= 2900
    if(!wxPersistenceManager::Get().Find(this)) {
        wxPersistenceManager::Get().RegisterAndRestore(this);
    } else {
        wxPersistenceManager::Get().Restore(this);
    }
#endif
    // Connect events
    m_dvListCtrl->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                          wxDataViewEventHandler(DiffFoldersBaseDlg::OnItemActivated), NULL, this);
    m_dvListCtrl->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU,
                          wxDataViewEventHandler(DiffFoldersBaseDlg::OnItemContextMenu), NULL, this);
}

DiffFoldersBaseDlg::~DiffFoldersBaseDlg()
{
    m_dvListCtrl->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED,
                             wxDataViewEventHandler(DiffFoldersBaseDlg::OnItemActivated), NULL, this);
    m_dvListCtrl->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_CONTEXT_MENU,
                             wxDataViewEventHandler(DiffFoldersBaseDlg::OnItemContextMenu), NULL, this);
}
