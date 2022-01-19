#pragma once
#include "Constants.h"
#include "MainWnd.h"
#include "ThreadList.h"
#include "CGameInfo.h" 
#include "MainOption.h"

class CMainApp
{
    private :
        CMainWnd m_MainWnd ; 
        CMainOption m_MainOption ; 
        CThreadList m_Threads ; 
        CGameInfo m_GameInfos ; 
        BlockId m_eId ;
        bool m_IsGameOver ;
        bool m_IsPaused ; 
    public :
        CMainApp() ;
        ~CMainApp() ;
    public :
        CMainWnd &GetMainWnd() ;
        CMainOption &GetMainOption() ; 
        CThreadList &GetThreadList() ; 
        CGameInfo &GetGameInfo() ; 
        BlockId GetBlockId() const ; 
        bool GetIsGameOver() const ; 
        bool GetIsPaused() const ; 
    public :
        void SetBlockId(BlockId eId) ; 
        void SetIsGameOver(bool bGameOver) ;
        void SetIsPaused(bool bPaused) ; 
    public :
        void Reset() ;
    public :
        int Run(HINSTANCE hInstance, int nCmdShow) ; 
    public :
        static CMainApp &GetInstance() ;
        static void Release() ;
} ;

