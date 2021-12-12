#include "pch.h" 
#include "Tetris.h"
#include "MainWnd.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    RECT rc { 100, 100, 500, 500 } ;
    CMainWnd MainWnd ; 
    MainWnd.Create(NULL, &rc, _T("Tetris"), WS_OVERLAPPEDWINDOW, 0) ;  
    MainWnd.ShowWindow(SW_SHOW) ; 
    MainWnd.UpdateWindow() ; 

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TETRIS));
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

