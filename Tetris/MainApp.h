#pragma once
#include "Constants.h"
#include "MainOption.h"

class CMainApp
{
    private :
        HWND m_hWnd ;
        BlockId m_eId ; 
        INT m_nScore ; 
        INT m_nLevel ; 
        INT m_nLine ; 
        bool m_IsGameOver ;
        CMainOption m_MainOption ; 
    public :
        CMainApp(HWND hWnd) ;
        ~CMainApp() ;
    public :
        HWND GetMainWnd() const ; 
        BlockId GetBlockId() const ; 
        INT GetScore() const ; 
        INT GetLevel() const ; 
        INT GetLine() const ; 
        bool GetIsGameOver() const ; 
        CMainOption *GetMainOption() ; 
    public :
        void SetMainWnd(HWND hWnd) ; 
        void SetBlockId(BlockId eId) ; 
        void SetScore(INT nScore) ; 
        void SetLevel(INT nScore) ; 
        void SetLine(INT nScore) ; 
        void SetIsGameOver(bool IsGameOver) ;
    public :
        void Reset() ;
    public :
        static CMainApp &GetInstance(HWND hWnd = nullptr) ;
        static void Release() ;
} ;

