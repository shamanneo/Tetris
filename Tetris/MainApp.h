#pragma once
#include "Constants.h"

class CMainApp
{
    private :
        HWND m_hWnd ;
        BlockId m_eId ; 
    public :
        CMainApp(HWND hWnd) ;
        ~CMainApp() ;
    public :
        HWND GetMainWnd() const ; 
        BlockId GetBlockId() const ; 
        void SetBlockId(BlockId eId) ; 
    public :
        static CMainApp &GetInstance(HWND hWnd = nullptr) ;
        static void Release() ;
} ;

