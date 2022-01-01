#include "pch.h"
#include "MainApp.h"

static CMainApp *g_pMainApp = nullptr; 

CMainApp::CMainApp(HWND hWnd)
{
    m_hWnd = hWnd ;
}

CMainApp::~CMainApp()
{

}

HWND CMainApp::GetMainWnd() const 
{
    return m_hWnd ;
}

BlockId CMainApp::GetBlockId() const 
{
    return m_eId ;
}

void CMainApp::SetBlockId(BlockId eId)  
{
    m_eId = eId ; 
}

//      static

CMainApp &CMainApp::GetInstance(HWND hWnd)
{
    if (g_pMainApp == nullptr)
    {
        ATLASSERT(hWnd != NULL) ;
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