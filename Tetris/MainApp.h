#pragma once
#include "Constants.h"

class CMainApp
{
    private :
        HWND m_hWnd ;
        HINSTANCE m_hInstance ; 
        BlockId m_eId ; 
        INT m_nScore ; 
        INT m_nLevel ; 
        INT m_nLine ; 
        bool m_IsGameOver ;
    public :
        CMainApp(HWND hWnd, HINSTANCE hInstance) ;
        ~CMainApp() ;
    public :
        HWND GetMainWnd() const ; 
        HINSTANCE GetMainInStance() const ; 
        BlockId GetBlockId() const ; 
        INT GetScore() const ; 
        INT GetLevel() const ; 
        INT GetLine() const ; 
        bool GetIsGameOver() const ; 
    public :
        void SetMainWnd(HWND hWnd) ; 
        void SetMainInstance(HINSTANCE hInstance) ; 
        void SetBlockId(BlockId eId) ; 
        void SetScore(INT nScore) ; 
        void SetLevel(INT nScore) ; 
        void SetLine(INT nScore) ; 
        void SetIsGameOver(bool IsGameOver) ;
    public :
        static CMainApp &GetInstance(HWND hWnd = nullptr, HINSTANCE hInstance = nullptr) ;
        static void Release() ;
} ;

