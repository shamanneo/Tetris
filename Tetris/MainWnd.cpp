#include "pch.h"
#include "resource.h" 
#include "Paint.h"
#include "MainApp.h"
#include "OptionsDlg.h"
#include "MainWnd.h"

CMainWnd::CMainWnd()
{
    m_IsEntered = false ; 
    m_nCurkey = 0 ;
} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &bHandled)
{
    bHandled = FALSE ;
    CMainApp::GetInstance().SetMainWnd(m_hWnd) ; 
    m_spComm = std::make_unique<CCommand>() ;
    return 0 ;
}

LRESULT CMainWnd::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL & /*bHandled*/)
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ;
    
    CPaint paint { m_hWnd, hDC } ;
    if(m_IsEntered == true)
    {
        CMainApp::GetInstance().SetScore(0) ; 
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

LRESULT CMainWnd::OnKeyDown(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL &/*bHandled*/) 
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
                SetTimer(IDT_DOWN_TIMER, DEFAULT_VELOCITY, NULL) ;
                
                InvalidateRect(nullptr) ; 
                UpdateWindow() ;
            }
            break ; 
        }
        case VK_ESCAPE :
        {
            /*
            COptionsDlg dlg ;
            if (dlg.DoModal(m_hWnd) == IDCANCEL)
            {
                return 0 ;
            }
            dlg.IsDlgButtonChecked(IDC_CHECK_GUIDE) ;
            */
            break ;
        }
        case VK_LEFT : // Move left.
        case VK_RIGHT : // Move right.
        case VK_UP : // Rotate clock-wise.
        case VK_DOWN : // Slow Down.
        case VK_SPACE : // Fast Down
        {
            m_nCurkey = (INT)wParam ; 
            break ;
        }
        default :
        {
            break ;
        }
    }
    return 0 ; 
}

LRESULT CMainWnd::OnTimer(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL &/*bHandled*/) 
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
            m_spComm->InputKey(m_nCurkey) ; 
            m_nCurkey = 0 ; 
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

LRESULT CMainWnd::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PostQuitMessage(0) ;
    return 0 ; 
}