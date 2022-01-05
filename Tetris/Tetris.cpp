#include "pch.h" 
#include <crtdbg.h>
#include "Tetris.h"
#include "MainWnd.h"
#include "Paint.h"
#include "MainApp.h"

using namespace Gdiplus ; 

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE /*hPrevInstance*/,
                     _In_ LPWSTR    /*lpCmdLine*/,
                     _In_ int       /*nCmdShow*/)
{
    _CrtMemState state ;
    _CrtMemCheckpoint(&state) ;
    
    RECT rc { 100, 100, 1209, 806 } ;
    CMainWnd *MainWnd = new CMainWnd ; 
    GdiplusStartupInput gdiplusStartupInput ; 
    ULONG_PTR gdiplusToken ; 
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL) ; 

    MainWnd->Create(NULL, &rc, _T("Tetris"), WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX, 0) ;  
    MainWnd->ShowWindow(SW_SHOW) ; 
    MainWnd->UpdateWindow() ; 

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS)) ;
    MSG msg ;

    SetTimer(*MainWnd, IDT_MAIN_DRAWING_TIMER, 300, NULL) ;  
    while (GetMessage(&msg, nullptr, 0, 0)) // main message loop.
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg) ;
            DispatchMessage(&msg) ;
        }
    }
    CMainApp::Release() ;
    GdiplusShutdown(gdiplusToken) ; 

    _CrtMemDumpAllObjectsSince(&state) ;
    return (int) msg.wParam ;
}
