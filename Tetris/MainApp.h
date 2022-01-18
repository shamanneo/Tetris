#pragma once
#include "Constants.h"
#include "MainWnd.h"
#include "ThreadList.h"
#include "MainOption.h"

class CMainApp
{
    private :
        CMainWnd m_MainWnd ; 
        CMainOption m_MainOption ; 
        CThreadList m_Threads ; 
        HWND m_hWnd ;
        BlockId m_eId ; 
        INT m_nScore ; 
        INT m_nLevel ; 
        INT m_nLine ; 
        bool m_IsGameOver ;
        bool m_IsPaused ; 
    public :
        CMainApp(HWND hWnd) ;
        ~CMainApp() ;
    public :
        HWND GetMainWnd() const ; 
        CMainOption *GetMainOption() ; 
        CThreadList &GetThreadList() ; 
        BlockId GetBlockId() const ; 
        INT GetScore() const ; 
        INT GetLevel() const ; 
        INT GetLine() const ; 
        bool GetIsGameOver() const ; 
        bool GetIsPaused() const ; 
    public :
        void SetMainWnd(HWND hWnd) ; 
        void SetBlockId(BlockId eId) ; 
        void SetScore(INT nScore) ; 
        void SetLevel(INT nScore) ; 
        void SetLine(INT nScore) ; 
        void SetIsGameOver(bool bGameOver) ;
        void SetIsPaused(bool bPaused) ; 
    public :
        void Reset() ;
    public :
        int Run(HINSTANCE hInstance, int nCmdShow) ; 
    public :
        static CMainApp &GetInstance(HWND hWnd = nullptr) ;
        static void Release() ;
} ;

