#include "pch.h"
#include <gdiplus.h>
#include "resource.h" 
#pragma comment (lib, "Gdiplus.lib")
#include "Paint.h"
#include "MainApp.h"
#include "MainWnd.h"

int nKey ; 

CMainWnd::CMainWnd()
{
    m_IsEntered = false ; 
} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    bHandled = FALSE ;
    CMainApp &MainApp = CMainApp::GetInstance(m_hWnd) ;   
    m_spComm = std::make_unique<CCommand>() ;
    return 0 ;
}

LRESULT CMainWnd::OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ;
    
    CPaint paint { m_hWnd, hDC } ;
    if(m_IsEntered == true)
    {
        //paint.DrawScores(0) ;
        paint.DrawBoard() ; 
        m_spComm->PaintBoard() ; 
        paint.PrintNextBlock() ; 
    }
    else 
    {
        paint.PrintMain() ;
    }
    
    EndPaint(&ps) ; 
    return 0 ;
}

LRESULT CMainWnd::OnKeyDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled) 
{
    switch(wParam)
    {
        case VK_RETURN :
        {
            if(m_IsEntered == false)
            {
                m_IsEntered = true ;
                KillTimer(IDT_MAIN_DRAWING_TIMER) ; 
                SetTimer(IDT_DRAW_TIMER, 0, NULL) ; 
                SetTimer(IDT_DOWN_TIMER, 300, NULL) ;
                
                InvalidateRect(nullptr) ; 
                UpdateWindow() ;
            }
            break ; 
        }
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
        case IDT_MAIN_DRAWING_TIMER :
        {
            CPaint paint { m_hWnd, hDC } ;
            paint.PrintMain() ; 
            break ; 
        }
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