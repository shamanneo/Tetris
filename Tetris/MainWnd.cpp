#include "pch.h"
#include "MainWnd.h"

CMainWnd::CMainWnd()
{

} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PAINTSTRUCT ps ; 
    BeginPaint(&ps) ; 

    EndPaint(&ps) ; 
    return 0 ;
}

LRESULT CMainWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PostQuitMessage(0) ;
    return 0 ; 
}