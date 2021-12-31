#include "pch.h"
#include "MainWnd.h"
#include "resource.h" 
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
#include "Paint.h"

int nKey ; 

CMainWnd::CMainWnd()
{
    m_spComm = std::make_unique<CCommand>() ;
} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    CPaint::Assign(m_hWnd) ;
    PAINTSTRUCT ps ; 
    BeginPaint(&ps) ;

    HDC hDC = GetDC() ; 
    CPaint paint ;
    paint.DrawScores(0) ;
    paint.DrawBoard() ; 
    paint.PrintNextBlock(0) ; 
    m_spComm->PaintBoard() ; 
    ReleaseDC(hDC) ; 

    EndPaint(&ps) ; 
    return 0 ;
}

LRESULT CMainWnd::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    switch(wParam)
    {
        case VK_LEFT : // Move left.
        {
            nKey = LEFT ; 
            break ;
        }
        case VK_RIGHT : // Move right.
        {
            nKey = RIGHT ; 
            break ;
        }
        case VK_UP : // Rotate clock-wise.
        {
            nKey = UP ; 
            break ;
        }
        case VK_DOWN : // Slow Down.
        {
            nKey = DOWN ; 
            break ;
        }
        case VK_SPACE : // Fast Down
        {
            nKey = SPACE ;
            break ; 
        }
        default :
        {
            break ;
        }
    }
    return 0 ; 
}

LRESULT CMainWnd::OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    HDC hDC = GetDC() ;
    switch(wParam)
    {
        case IDT_DRAW_TIMER :
        {
            m_spComm->InputKey(nKey) ; 
            nKey = 0 ; 
            break ; 
        }
        case IDT_DOWN_TIMER :
        {
            m_spComm->Down() ; 
            break ; 
        }
    }
    ReleaseDC(hDC) ;
    return 0 ; 
}

LRESULT CMainWnd::OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PostQuitMessage(0) ;
    return 0 ; 
}