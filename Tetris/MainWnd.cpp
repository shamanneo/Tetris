#include "pch.h"
#include "resource.h" 
#include "Paint.h"
#include "MainApp.h"
#include "OptionsDlg.h"
#include "MainWnd.h"

CMainWnd::CMainWnd()
{
    m_bEntered = false ; 
} 

CMainWnd::~CMainWnd()
{

}

LRESULT CMainWnd::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &bHandled)
{
    bHandled = FALSE ;
    return 0 ;
}

LRESULT CMainWnd::OnPaint(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL &/*bHandled*/)
{
    PAINTSTRUCT ps ; 
    HDC hDC = BeginPaint(&ps) ;
    
    CPaint paint { m_hWnd, hDC } ;
    if(m_bEntered == true)
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
            if(CMainApp::GetInstance().GetIsGameOver()) // ����ŸƮ, Ȥ�� ���ӿ��� �� �� �ٽ� �����ϴ°�?
            {
                CMainApp::GetInstance().GetGameInfo().Reset() ; 
                Start() ; 
            }
            if(m_bEntered == false) 
            {
                m_bEntered = true ;
                KillTimer(IDT_MAIN_DRAWING_TIMER) ; 
                Start() ; 
            }
            break ; 
        }
        case VK_ESCAPE :
        {
            COptionsDlg OptionDlg { m_bEntered }  ; 
            OptionDlg.DoModal() ; 
            break ;
        }
        default :
        {
            if((m_bEntered == true) && !CMainApp::GetInstance().GetIsGameOver())
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
    paint.DrawLeaderBoard() ; 
    CMainApp::GetInstance().GetGameInfo().Draw(m_hWnd) ; 
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
        case VK_UP : // �ð���� ȸ�� 
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
        case 'Z' : // �ݽð���� ȸ��
        {
            m_spTetrisGm->Rotate(COUNTER_CLOCKWISE_ROTATE) ; 
            break ;
        }
        default :
        {
            break ; 
        } 
    }
    if(!CMainApp::GetInstance().GetIsGameOver()) // ���� ���ӿ������, ���� ���� �׸� �ʿ䰡 ����
    {
        m_spTetrisGm->Draw() ; // ���� �� �ٴڿ� ������ ��, �ٷ� ���� ���� �׸�         
    }
}