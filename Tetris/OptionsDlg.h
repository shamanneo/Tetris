#pragma once
#include "resource.h"

class COptionsDlg : public CDialogImpl<COptionsDlg>
{
    private :
        bool m_bGuideChecked ;
    public :
        enum { IDD = IDD_OPTIONS } ;

        BEGIN_MSG_MAP(COptionsDlg)
            MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
            COMMAND_ID_HANDLER(IDOK, OnOK)
            COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
        END_MSG_MAP()

        LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
        LRESULT OnCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
};

