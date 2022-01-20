#pragma once
#include "Resource.h"

class CGameOverDlg : public CDialogImpl<CGameOverDlg> 
{
    private :
    public :
        CGameOverDlg() ; 
        ~CGameOverDlg() ; 
    public :
        enum { IDD = IDD_GAMEOVER_SCORE } ; 

        BEGIN_MSG_MAP(CGameOverDlg) 
            MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
            COMMAND_ID_HANDLER(IDOK, OnOK) 
            COMMAND_ID_HANDLER(IDCANCEL, OnCancel)
            COMMAND_HANDLER(IDC_INIT_TEXT_BOX, EN_CHANGE, OnEnChangeEditInit)
        END_MSG_MAP()
    public :
        LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/) ;
        LRESULT OnOK(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
        LRESULT OnCancel(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
        LRESULT OnEnChangeEditInit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/) ;
    public :
        static void InitCriticalSection() ; 
        static void DeleCriticalSection() ; 
        
} ;

