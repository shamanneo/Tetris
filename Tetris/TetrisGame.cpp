#include "pch.h"
#include <set>
#include <random>
#include "MainApp.h"
#include "Resource.h"
#include "Licky.h"
#include "Ricky.h"
#include "Cleveland.h"
#include "Phodeisland.h"
#include "Teewee.h" 
#include "Smashboy.h" 
#include "Hero.h" 
#include "Paint.h" 
#include "GameOverDlg.h" 
#include "CGameInfo.h" 
#include "TetrisGame.h"

const FLOAT DEFAULT_WAIT_TIME_ON_BLOCK = 0.7f ;  

CTetrisGame::CTetrisGame()
    : m_nArrSize(DEFAULT_ARRAY_SIZE), m_eNextId(BlockId::ID_VOID), m_nVelocity(DEFAULT_VELOCITY)
{
    m_nScore = 0 ; 
    m_fWaitTime = 0.0f ;
    m_CanSetTimer = true ; 
    for(INT nY = 0 ; nY < BLOCK_HEIGHT_COUNT ; nY++)
    {
        m_arrBoard[0][nY] = BOARD_BOUND ; 
        m_arrBoard[1][nY] = BOARD_BOUND ; 
        m_arrBoard[12][nY] = BOARD_BOUND ;
        m_arrBoard[13][nY] = BOARD_BOUND ;
        if(nY < 12)
        {
            m_arrBoard[nY][BLOCK_HEIGHT_COUNT - 1] = BOARD_BOUND ; 
        }
    }
}

CTetrisGame::~CTetrisGame()
{

}

void CTetrisGame::Create()
{
    SetLevel() ; 
    std::random_device dev ; 
    std::mt19937 rng { dev() } ;
    std::uniform_int_distribution<std::mt19937::result_type> dist6 { 0, 6 } ; 
    BlockId arrBlockId[7] { BlockId::ID_LICKY, BlockId::ID_RICKY, BlockId::ID_CLEVELAND, BlockId::ID_PHODEISLAND, BlockId::ID_TEEWEE, BlockId::ID_SMASHBOY, BlockId::ID_HERO } ; 
    BlockId eId ;
    if(m_eNextId == BlockId::ID_VOID)
    {
        eId = arrBlockId[dist6(rng)] ; 
    }
    else
    {
        eId = m_eNextId ; 
    }
    m_eNextId = arrBlockId[dist6(rng)] ; 
    switch(eId)
    {
        case BlockId::ID_LICKY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CLicky>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CLicky>(m_nArrSize) ; 
            break ;
        }
        case BlockId::ID_RICKY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CRicky>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CRicky>(m_nArrSize) ; 
            break ;
        }
        case BlockId::ID_CLEVELAND :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CCleveland>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CCleveland>(m_nArrSize) ; 
            break ;
        }
        case BlockId::ID_PHODEISLAND :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CPhodeisland>(m_nArrSize) ;
            m_spFurBk = std::make_unique<CPhodeisland>(m_nArrSize) ; 
            break ;
        }
        case BlockId::ID_TEEWEE :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ;
            m_spCurBk = std::make_unique<CTeewee>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CTeewee>(m_nArrSize) ; 
            break ;
        }
        case BlockId::ID_SMASHBOY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CSmashboy>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CSmashboy>(m_nArrSize) ; 
            break ;
        }
        case BlockId::ID_HERO :
        {
            m_nArrSize = HERO_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CHero>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CHero>(m_nArrSize) ; 
            break ;
        }
    }
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ; 
    CMainApp::GetInstance().SetBlockId(m_eNextId) ; 
    paint.PrintNextBlock() ; 
    DrawGhost() ; 
}

void CTetrisGame::Reach()
{
    INT nX = 0 ;
    INT nY = 0 ;
    INT nLine = 0 ; 
    INT nCount = 0 ; 
    std::set<INT> setYs ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++) // 가상의 보드에 블럭 각각의 ID값을 저장함
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            m_arrBoard[nX][nY] = (INT)m_spCurBk->GetId() ; 
            setYs.insert(nY) ; // 블럭의 층을 세트에 저장
        }
    }
    if(IsGameOver())
    {
        GameOver() ; 
        return ; 
    }
    for(auto it = setYs.begin() ; it != setYs.end() ; it++) // 떨어진 블럭의 층들을 검사함
    {
        nLine = *it ; 
        if(IsFull(nLine))
        {
            nCount++ ; 
            CMainOption &MainOption = CMainApp::GetInstance().GetMainOption() ; 
            if(MainOption.m_bAnimationCheck)
            {
                CPaint paint { CMainApp::GetInstance().GetMainWnd() } ; 
                paint.EraseAnimation(m_arrBoard, nLine) ; 
            }
            InUpdate(nLine) ; // 외부 UI 갱신
            OutUpdate() ; // 내부 로직 갱신
            CGameInfo &GameInfo = CMainApp::GetInstance().GetGameInfo() ; 
            GameInfo.StackScore(100 * nCount) ; 
            GameInfo.StackLine(1) ; 
            GameInfo.Draw(CMainApp::GetInstance().GetMainWnd().m_hWnd) ; 
        }
    }
    Create() ; 
}

void CTetrisGame::Stay()
{
    m_fWaitTime += 0.1f ; 
}

bool CTetrisGame::IsFull(INT nLine) 
{
    for(INT nX = 2 ; nX <= 11 ; nX++)
    {
        if(m_arrBoard[nX][nLine] == BLOCK_ARRAY_SPACE_OFF)
        {
            return false ; 
        }
    }
    return true ; 
}

void CTetrisGame::InUpdate(INT nLine)
{   
    for(INT nX = 2 ; nX <= 11 ; nX++)
    {
        m_arrBoard[nX][nLine] = BLOCK_ARRAY_SPACE_OFF ; 
    }
    for(INT nX = 2 ; nX <= 11 ; nX++)
    {
        for(INT nY = nLine - 1 ; nY > 1 ; nY--)
        {
            m_arrBoard[nX][nY + 1] = m_arrBoard[nX][nY] ; 
        }
    }
}

void CTetrisGame::OutUpdate()
{
    CPaint paint { CMainApp::GetInstance().GetMainWnd() } ;
    paint.EraseBoard() ; 
    paint.PaintBoard(m_arrBoard) ; 
}

void CTetrisGame::SetLevel() 
{
    HWND hWnd = CMainApp::GetInstance().GetMainWnd() ; 
    INT nCurScore = CMainApp::GetInstance().GetGameInfo().GetScore() ;
    if(nCurScore - m_nScore >= 950)
    {
        CMainApp::GetInstance().GetGameInfo().StackLevel(1) ; 
        KillTimer(hWnd, IDT_DOWN_TIMER) ; 
        if(m_nVelocity != 1)
        {
            m_nVelocity -= 5 ;
        }
        SetTimer(hWnd, IDT_DOWN_TIMER, m_nVelocity, NULL) ; 
        m_nScore += 1000 ; 
    }
}

bool CTetrisGame::IsGameOver()
{
    if(CMainApp::GetInstance().GetIsGameOver()) // Gameover된 후 다시 시작하기 위한 변수
    {
        return true ; 
    }
    for(INT nX = 2 ; nX <= 11 ; nX++)
    {
        if(m_arrBoard[nX][1] != BLOCK_ARRAY_SPACE_OFF)
        {
            return true ; 
        }
    }
    return false ; 
}

void CTetrisGame::GameOver() 
{
    HWND hWnd = CMainApp::GetInstance().GetMainWnd() ;
    CMainApp::GetInstance().SetIsGameOver(true) ; 
    CPaint paint { hWnd } ;
    paint.PaintBoard(m_arrBoard) ; 
    paint.PrintGameOver() ;
    KillTimer(hWnd, IDT_DOWN_TIMER) ;
  
    CGameOverDlg GameOverDlg ; 
    GameOverDlg.DoModal() ; 
}

bool CTetrisGame::IsLastBlock() 
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = m_nArrSize - 1 ; nIndex >= 0 ; nIndex--)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if(nY == 1)
            {
                return true ; 
            }
        }
    }
    return false ; 
}

void CTetrisGame::Draw()
{
    if(m_spCurBk != nullptr)
    {
        m_spCurBk->Draw(ALIVE_BLOCK) ;
    }
}

void CTetrisGame::Erase()
{
    m_spCurBk->Erase() ;
}

void CTetrisGame::DrawGhost() 
{
    if(m_spFurBk != nullptr)
    {
        CMainOption &MainOption = CMainApp::GetInstance().GetMainOption() ; 
        m_spFurBk->Erase() ; 
        if(MainOption.m_bGhostCheck)
        {
            *m_spFurBk = *m_spCurBk ; 
            while(IsMoveDown(m_spFurBk.get()))
            {
                m_spFurBk->Down() ; 
            }
            m_spFurBk->Draw(GHOST_BLOCK) ; 
        }
    }
}

void CTetrisGame::Left()
{
    if(IsMoveLeft())
    {
        Erase() ; 
        m_spCurBk->Left() ; 
        DrawGhost() ;
    }
}

void CTetrisGame::Right() 
{   
    if(IsMoveRight())
    {
        Erase() ; 
        m_spCurBk->Right() ; 
        DrawGhost() ;
    }
}

void CTetrisGame::Rotate(INT nDirect)
{
    Erase() ; 
    m_spCurBk->Rotate(m_arrBoard, nDirect) ; 
    DrawGhost() ;
}

void CTetrisGame::Down() 
{
    Erase() ; 
    if(IsMoveDown(m_spCurBk.get()))
    {
        m_spCurBk->Down() ; 
        m_spCurBk->Draw(ALIVE_BLOCK) ; 
    }
}

bool CTetrisGame::SlowDown()
{
    if(IsMoveDown(m_spCurBk.get()))
    {
        Down() ; 
        return false ; 
    }
    else // 맨 밑의 층에 도달, 블럭 위에서도 움직임이 가능해야함
    {
        if(IsLastBlock()) // 마지막 블럭일 때는 시간을 주지 않음
        {
            Reach() ; 
            return true ; 
        }
        if(m_CanSetTimer) // 타이머는 단 한번만 설정
        {
            SetTimer(CMainApp::GetInstance().GetMainWnd(), IDT_STAY_TIMER, 300, NULL) ;  
            m_CanSetTimer = false ; 
        }
        if(m_fWaitTime >= DEFAULT_WAIT_TIME_ON_BLOCK) 
        {                                             
            KillTimer(CMainApp::GetInstance().GetMainWnd(), IDT_STAY_TIMER) ;
            m_CanSetTimer = true ; 
            Reach() ; 
            m_fWaitTime = 0.0f ; 
            return true ; 
        }
        m_spCurBk->Draw(ALIVE_BLOCK) ; 
        return false ; 
    }
}

void CTetrisGame::FastDown() 
{
    Erase() ; 
    while(IsMoveDown(m_spCurBk.get()))
    {
        m_spCurBk->Down() ; 
    }
    m_spCurBk->Draw(ALIVE_BLOCK) ; 
    Reach() ; 
    CGameInfo &GameInfo = CMainApp::GetInstance().GetGameInfo() ;
    GameInfo.StackScore(30) ; 
    GameInfo.Draw(CMainApp::GetInstance().GetMainWnd().m_hWnd) ; 
}

bool CTetrisGame::IsMoveLeft() 
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if(m_arrBoard[nX - 1][nY] != BLOCK_ARRAY_SPACE_OFF)
            {
                return false ; 
            }
        }
    }
    return true ; 
}

bool CTetrisGame::IsMoveRight() 
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            if(m_arrBoard[nX + 1][nY] != BLOCK_ARRAY_SPACE_OFF)
            {
                return false ; 
            }
        }
    }
    return true ; 
}

bool CTetrisGame::IsMoveDown(CBlock *pBk)
{
    INT nX = 0 ;
    INT nY = 0 ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(pBk->GetPos(nIndex, nX, nY))
        {
            if(m_arrBoard[nX][nY + 1] != BLOCK_ARRAY_SPACE_OFF)
            {
                return false ; 
            }
        }
    }
    return true ; 
}