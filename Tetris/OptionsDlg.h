#pragma once
#include "resource.h"

class COptionsDlg : public CDialogImpl<COptionsDlg>
{
    private :
    public :
        COptionsDlg() ; 
        ~COptionsDlg() ; 
    public :
        enum { IDD = IDD_OPTIONS } ;

        BEGIN_MSG_MAP(COptionsDlg)
            MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
            COMMAND_ID_HANDLER(IDOK, OnOK)
            COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
            COMMAND_HANDLER(IDC_CHECK_GHOST, BN_CLICKED, OnCheckGhost)
        END_MSG_MAP()

        LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/) ;
        LRESULT OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
        LRESULT OnCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
        LRESULT OnCheckGhost(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
    public :
        void Save() ; 
        void Load() ; 
} ;

