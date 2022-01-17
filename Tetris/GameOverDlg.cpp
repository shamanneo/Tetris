#include "pch.h"
#include "MainApp.h"
#include "SQLlite/sqlite3.h" 
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
    CStringA strSql ; 
    CStringA strInit ; 
    ::GetDlgItemTextA(m_hWnd, IDC_INIT_TEXT_BOX, strInit.GetBuffer(), 4) ; 
    char *zErrMsg = nullptr ; 
    strSql.Format("INSERT INTO TETRIS_SCORE(ID, NAME, SCORE) VALUES (1, '%s', %d)", static_cast<LPCSTR>(strInit), CMainApp::GetInstance().GetScore()) ; 
    sqlite3 *db ; 
    sqlite3_open("Tetris.db", &db) ; 
    const char *sql = strSql ; 
    sqlite3_exec(db, sql, 0, 0, &zErrMsg) ; 
    sqlite3_close(db) ; 
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
	return 0 ;
}
