#include "pch.h" 
#include <iostream>
#include <crtdbg.h>
#include "SQLlite/sqlite3.h" 
#include "MainApp.h"
#include "Tetris.h"

using namespace Gdiplus ; 

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE /*hPrevInstance*/,
                     _In_ LPWSTR    /*lpCmdLine*/,
                     _In_ int       nCmdShow)
{
    GdiplusStartupInput gdiplusStartupInput ; 
    ULONG_PTR gdiplusToken ; 
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL) ; 
    CMainApp &MainApp = CMainApp::GetInstance() ; 
    int nResult = MainApp.Run(hInstance, nCmdShow) ; 

    CMainApp::GetInstance().GetThreadList().WaitForAll() ;
    CMainApp::GetInstance().GetThreadList().RemoveAll() ;

    CMainApp::Release() ;
    GdiplusShutdown(gdiplusToken) ; 
    _CrtDumpMemoryLeaks() ; 
    return nResult ; 
}
