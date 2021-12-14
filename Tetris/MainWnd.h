#pragma once
#include "TetrisGame.h"

class CMainWnd : public CWindowImpl<CMainWnd>
{
    private :
        std::unique_ptr<CTetrisGame> m_spTetrisGm ; 
    public :
        CMainWnd() ; 
        ~CMainWnd() ;
    public :
        DECLARE_WND_CLASS(_T("MainWnd")) ; 

        BEGIN_MSG_MAP(CMainWnd) 
            MESSAGE_HANDLER(WM_PAINT, OnPaint) 
            MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown) 
            MESSAGE_HANDLER(WM_TIMER, OnTimer) 
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
        END_MSG_MAP()
    public :    
        LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ; 
        LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ; 
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ; 
} ; 


