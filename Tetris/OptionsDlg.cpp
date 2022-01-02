#include "pch.h"
#include "OptionsDlg.h"

LRESULT COptionsDlg::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    CheckDlgButton(IDC_CHECK_GUIDE, BST_CHECKED) ;
    SetDlgItemText(IDC_EDIT1, _T("Hello, World")) ;
    CenterWindow() ;
    return 0 ;
}

LRESULT COptionsDlg::OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    EndDialog(IDOK) ;
    return 0 ;
}

LRESULT COptionsDlg::OnCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    EndDialog(IDCANCEL) ;
    return 0 ;
}