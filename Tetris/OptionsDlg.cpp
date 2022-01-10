#include "pch.h"
#include "MainApp.h"
#include "OptionsDlg.h"

COptionsDlg::COptionsDlg()
{

}

COptionsDlg::~COptionsDlg()
{

}

LRESULT COptionsDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    if(CMainApp::GetInstance().GetMainOption().IsCheckedGhost())
    {
        CheckDlgButton(IDC_CHECK_GHOST, BST_CHECKED) ;
    }
    else
    {
        CheckDlgButton(IDC_CHECK_GHOST, BST_UNCHECKED) ;
    }
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

LRESULT COptionsDlg::OnCheckGhost(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    if(IsDlgButtonChecked(IDC_CHECK_GHOST))
    {
        CMainApp::GetInstance().GetMainOption().SetCheckGhost(true) ;
        return 0 ;
    }
    CMainApp::GetInstance().GetMainOption().SetCheckGhost(false) ;
    return 0 ;
}
