#include "pch.h"
#include "resource.h" 
#include "Paint.h"
#include "MainApp.h"
#include "OptionsDlg.h"
#include "MainWnd.h"

CMainWnd::CMainWnd()
{
    m_IsEntered = false ; 
} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &bHandled)
{
    CMainApp::GetInstance().SetMainWnd(m_hWnd) ; 
    bHandled = FALSE ;
    return 0 ;
}

LRESULT CMainWnd::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ;
    
    CPaint paint { m_hWnd, hDC } ;
    if(m_IsEntered == true)
    {
        PaintDefault(paint) ; 
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
            if(CMainApp::GetInstance().GetIsGameOver()) // 리스타트, 혹시 게임오버 인 후 다시 접근하는가?
            {
                Start() ; 
            }
            if(m_IsEntered == false) 
            {
                m_IsEntered = true ;
                KillTimer(IDT_MAIN_DRAWING_TIMER) ; 
                Start() ; 
            }
            break ; 
        }
        case VK_ESCAPE :
        {
            COptionsDlg OptionDlg ; 
            OptionDlg.DoModal() ; 
            break ;
        }
        default :
        {
            if((m_IsEntered == true) && !CMainApp::GetInstance().GetIsGameOver())
            {
                ControlKey(wParam) ;
            }
            break ;
        }
    }
    return 0 ; 
}

LRESULT CMainWnd::OnTimer(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL &/*bHandled*/) 
{
    if(CMainApp::GetInstance().GetIsPaused())
    {
        return 0 ; 
    }
    HDC hDC = GetDC() ;
    switch(wParam)
    {
        case IDT_MAIN_DRAWING_TIMER :
        {
            CPaint paint { m_hWnd, hDC } ;
            paint.PrintMain() ; 
            break ; 
        }
        case IDT_DOWN_TIMER :
        {
            m_spTetrisGm->SlowDown() ; 
            break ; 
        }
        case IDT_STAY_TIMER :
        {
            m_spTetrisGm->Stay() ; 
            break ; 
        }
        default :
        {
            ATLASSERT(0) ; 
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

//      Custom

void CMainWnd::Start()
{
    CMainApp::GetInstance().Reset() ; 
    SetTimer(IDT_DOWN_TIMER, DEFAULT_VELOCITY, NULL) ;
    m_spTetrisGm = std::make_unique<CTetrisGame>() ;
    InvalidateRect(nullptr) ; 
    UpdateWindow() ;
    m_spTetrisGm->Create() ; 
}

void CMainWnd::PaintDefault(CPaint &paint)
{
    paint.DrawRankingBoard() ; 
    CMainApp::GetInstance().SetScore(0) ; 
    paint.DrawBoard() ; 
    paint.PrintNextBlock() ;
    m_spTetrisGm->OutUpdate() ; 
    m_spTetrisGm->Draw() ; 
    m_spTetrisGm->DrawGhost() ; 
}

void CMainWnd::ControlKey(WPARAM wParam)
{
    switch(wParam)
    {
        case VK_RETURN :
        {
            break ; 
        }
        case VK_LEFT :
        {
            m_spTetrisGm->Left() ; 
            break ; 
        }
        case VK_RIGHT :
        {
            m_spTetrisGm->Right() ; 
            break ; 
        }
        case VK_UP : // 시계방향 회전 
        {
            m_spTetrisGm->Rotate(CLOCKWISE_ROTATE) ; 
            break ; 
        }
        case VK_DOWN :
        {
            m_spTetrisGm->Down() ; 
            break ; 
        }
        case VK_SPACE :
        {
            m_spTetrisGm->FastDown() ; 
            break ; 
        }
        case 'Z' : // 반시계방향 회전
        {
            m_spTetrisGm->Rotate(COUNTER_CLOCKWISE_ROTATE) ; 
            break ;
        }
        default :
        {
            break ; 
        } 
    }
    if(!CMainApp::GetInstance().GetIsGameOver()) // 만약 게임오버라면, 다음 블럭을 그릴 필요가 없음
    {
        m_spTetrisGm->Draw() ; // 블럭이 밑 바닥에 도착한 후, 바로 다음 블럭을 그림         
    }
}