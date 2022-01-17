#include "pch.h"
#include "GameOverDlg.h"

CGameOverDlg::CGameOverDlg()
{

}

CGameOverDlg::~CGameOverDlg()
{

}

LRESULT CGameOverDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    CenterWindow() ; 
    return 0 ; 
}

LRESULT CGameOverDlg::OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) 
{
    EndDialog(IDOK) ; 
    return 0 ; 
}

LRESULT CGameOverDlg::OnCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    EndDialog(IDCANCEL) ; 
    return 0 ; 
}

LRESULT CGameOverDlg::OnEnChangeEditInit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
    GetDlgItemTextW(IDC_INIT_TEXT_BOX, this->m_szBuffer, 4) ; 
	return 0 ;
}
