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
}

CMainApp::~CMainApp()
{

}

//      Getter

HWND CMainApp::GetMainWnd() const 
{
    return m_hWnd ;
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

void CMainApp::SetIsGameOver(bool IsGameOver)
{
    m_IsGameOver = IsGameOver ; 
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