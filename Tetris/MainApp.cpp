#include "pch.h"
#include "Paint.h"
#include "MainApp.h"

static CMainApp *g_pMainApp = nullptr ; 

CMainApp::CMainApp(HWND hWnd)
{
    m_hWnd = hWnd ;
    m_eId = BlockId::ID_VOID ; 
    m_nScore = 0 ; 
    m_nLevel = 1 ; 
    m_nLine = 0 ;
    m_IsGameOver = false ; 
    m_IsPaused = false ; 
}

CMainApp::~CMainApp()
{

}

//      Getter

HWND CMainApp::GetMainWnd() const 
{
    return m_hWnd ;
}

CMainOption *CMainApp::GetMainOption() 
{
    return &m_MainOption ; 
}

CThreadList &CMainApp::GetThreadList() 
{
    return m_Threads ; 
}

BlockId CMainApp::GetBlockId() const 
{
    return m_eId ;
}

INT CMainApp::GetScore() const 
{
    return m_nScore ; 
}

INT CMainApp::GetLevel() const 
{
    return m_nLevel ; 
}

INT CMainApp::GetLine() const 
{
    return m_nLine ; 
}

bool CMainApp::GetIsGameOver() const
{
    return m_IsGameOver ; 
}

bool CMainApp::GetIsPaused() const 
{
    return m_IsPaused ; 
}

//      Setter

void CMainApp::SetMainWnd(HWND hWnd) 
{
    m_hWnd = hWnd ; 
}

void CMainApp::SetBlockId(BlockId eId)  
{
    m_eId = eId ; 
}

void CMainApp::SetScore(INT nScore)  
{
    m_nScore += nScore ; 
    CPaint paint { m_hWnd } ; 
    paint.DrawInfo(m_nScore, m_nLevel, m_nLine) ; 
}

void CMainApp::SetLevel(INT nLevel)  
{
    m_nLevel += nLevel ; 
    CPaint paint { m_hWnd } ; 
    paint.DrawInfo(m_nScore, m_nLevel, m_nLine) ; 
}

void CMainApp::SetLine(INT nLine)  
{
    m_nLine += nLine ; 
    CPaint paint { m_hWnd } ; 
    paint.DrawInfo(m_nScore, m_nLevel, m_nLine) ; 
}

void CMainApp::SetIsGameOver(bool bGameOver)
{
    m_IsGameOver = bGameOver ; 
}

void CMainApp::SetIsPaused(bool bPaused)
{
    m_IsPaused = bPaused ; 
}

void CMainApp::Reset()
{
    m_eId = BlockId::ID_VOID ; 
    m_nScore = 0 ; 
    m_nLevel = 1 ; 
    m_nLine = 0 ;
    m_IsGameOver = false ; 
}

int CMainApp::Run(HINSTANCE hInstance, int nCmdShow) 
{
    
    RECT rc { 100, 100, 1209, 806 } ; // Main Window size
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS)) ;
    MSG msg ;

    m_MainWnd.Create(NULL, &rc, _T("Tetris"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 0) ;  
    m_MainWnd.ShowWindow(nCmdShow) ; 
    m_MainWnd.UpdateWindow() ; 

    SetTimer(m_MainWnd, IDT_MAIN_DRAWING_TIMER, 300, NULL) ;  
    while (::GetMessage(&msg, nullptr, 0, 0)) // main message loop.
    {
        if (!::TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            ::TranslateMessage(&msg) ;
            ::DispatchMessage(&msg) ;
        }
    }
    return (int) msg.wParam ; 
}

//      static

CMainApp &CMainApp::GetInstance(HWND hWnd)
{
    if (g_pMainApp == nullptr)
    {
        g_pMainApp = new CMainApp { hWnd } ;
    }
    return *g_pMainApp ;
}

void CMainApp::Release()
{
    if (g_pMainApp != nullptr)
    {
        delete g_pMainApp ;
        g_pMainApp = nullptr ;
    }
}