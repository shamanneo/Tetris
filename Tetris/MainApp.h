#pragma once

class CMainApp
{
    private :
        HWND m_hWnd ;
    public :
        CMainApp(HWND hWnd) ;
        ~CMainApp() ;
    public :
        HWND GetMainWnd() ;
        static CMainApp &GetInstance(HWND hWnd = nullptr) ;
        static void Release() ;
} ;

