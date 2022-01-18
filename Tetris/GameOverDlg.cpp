#include "pch.h"
#include "MainApp.h"
#include "ThreadList.h"
#include "SQLlite/sqlite3.h" 
#include "GameOverDlg.h"

unsigned int __stdcall RecordThread(void *arg)
{
    INT rc = 0 ; 
    CStringA strSql ; 
    CStringA *strInit = reinterpret_cast<CStringA *>(arg) ; 
    char *zErrMsg = nullptr ; 
    const char *sql = nullptr ; 
    sqlite3 *db ; 
    sqlite3_open("Tetris.db", &db) ; 
    sql = "SELECT * from TETRIS_SCORE" ; 
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg) ; 
    if(rc == SQLITE_ERROR)
    {
        sql = "CREATE TABLE TETRIS_SCORE(ID, Name, Score)" ; 
        rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg) ; 
    }
    strSql.Format("INSERT INTO TETRIS_SCORE(ID, Name, Score) VALUES (1, '%s', %d)", static_cast<LPCSTR>(*strInit), CMainApp::GetInstance().GetScore()) ; 
    sql = strSql ; 
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg) ; 
    ATLASSERT(!rc) ; 
    sqlite3_close(db) ; 
    delete strInit ; 
    return 0 ; 
}

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
    CStringA *pStrInit = new CStringA ; 
    CString strText ;
    GetDlgItemText(IDC_INIT_TEXT_BOX, strText) ;
    *pStrInit = strText ;
    HANDLE hThread = reinterpret_cast<HANDLE>(_beginthreadex(nullptr, 0, RecordThread, pStrInit, 0, nullptr)) ; 
    CThreadList &Threads = CMainApp::GetInstance().GetThreadList() ; 
    Threads.Add(hThread) ; 
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
