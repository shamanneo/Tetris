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
    CMainApp::GetInstance().SetIsPaused(true) ; 
    return 0 ;
}

LRESULT COptionsDlg::OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    Save() ; 
    EndDialog(IDOK) ;
    CMainApp::GetInstance().SetIsPaused(false) ; 
    return 0 ;
}

LRESULT COptionsDlg::OnCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    EndDialog(IDCANCEL) ;
    CMainApp::GetInstance().SetIsPaused(false) ; 
    return 0 ;
}

LRESULT COptionsDlg::OnCheckGhost(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    return 0 ;
}

LRESULT COptionsDlg::OnCheckAnimation(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    return 0 ;
}

void COptionsDlg::Save()
{
    CMainOption *MainOption = CMainApp::GetInstance().GetMainOption() ; 
    (IsDlgButtonChecked(IDC_CHECK_GHOST)) ? MainOption->m_bGhostCheck = true : MainOption->m_bGhostCheck = false ; // 고스트 블럭 설정 관리
    (IsDlgButtonChecked(IDC_CHECK_ANIMATION)) ? MainOption->m_bAnimationCheck = true : MainOption->m_bAnimationCheck = false ; // 애니메이션 설정 관리
}

void COptionsDlg::Load()
{
    CMainOption *MainOption = CMainApp::GetInstance().GetMainOption() ; 
    (MainOption->m_bGhostCheck) ? CheckDlgButton(IDC_CHECK_GHOST, BST_CHECKED) : CheckDlgButton(IDC_CHECK_GHOST, BST_UNCHECKED) ; 
    (MainOption->m_bAnimationCheck) ? CheckDlgButton(IDC_CHECK_ANIMATION, BST_CHECKED) : CheckDlgButton(IDC_CHECK_ANIMATION, BST_UNCHECKED) ; 
}

