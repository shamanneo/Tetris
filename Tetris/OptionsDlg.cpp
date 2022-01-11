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
    Load() ; 
    CenterWindow() ;
    return 0 ;
}

LRESULT COptionsDlg::OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    Save() ; 
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
    return 0 ;
}

void COptionsDlg::Save()
{
    CMainOption *MainOption = CMainApp::GetInstance().GetMainOption() ; 
    (IsDlgButtonChecked(IDC_CHECK_GHOST)) ? MainOption->m_bGhostCheck = true : MainOption->m_bGhostCheck = false ; // 고스트 블럭 설정 관리
}

void COptionsDlg::Load()
{
    CMainOption *MainOption = CMainApp::GetInstance().GetMainOption() ; 
    (MainOption->m_bGhostCheck) ? CheckDlgButton(IDC_CHECK_GHOST, BST_CHECKED) : CheckDlgButton(IDC_CHECK_GHOST, BST_UNCHECKED) ; 
}
