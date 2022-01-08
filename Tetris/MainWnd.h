#pragma once
#include <memory>
#include "Command.h"

class CMainWnd : public CWindowImpl<CMainWnd>
{
    private :
        std::unique_ptr<CCommand> m_spComm ; 
        bool m_IsEntered ; 
        INT m_nCurkey ; 
    public :
        CMainWnd() ; 
        ~CMainWnd() ;
    public :
        DECLARE_WND_CLASS_EX(_T("MainWnd"), CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS, COLOR_WINDOW + 2) ; 

        BEGIN_MSG_MAP(CMainWnd) 
            MESSAGE_HANDLER(WM_CREATE, OnCreate) 
            MESSAGE_HANDLER(WM_PAINT, OnPaint) 
            MESSAGE_HANDLER(WM_KEYDOWN, OnKeyDown) 
            MESSAGE_HANDLER(WM_TIMER, OnTimer) 
            MESSAGE_HANDLER(WM_DESTROY, OnDestroy) 
        END_MSG_MAP()
    public :    
        virtual void OnFinalMessage(HWND) override ;
        LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ;
        LRESULT OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ; 
        LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ; 
        LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) ; 
    public :
        void Start() ; 
} ; 

inline void CMainWnd::OnFinalMessage(HWND)
{
    delete this ;
}
   




