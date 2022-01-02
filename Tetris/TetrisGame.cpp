#include "pch.h"
#include <time.h>
#include <set>
#include "MainApp.h"
#include "Licky.h"
#include "Ricky.h"
#include "Cleveland.h"
#include "Phodeisland.h"
#include "Teewee.h" 
#include "Smashboy.h" 
#include "Hero.h" 
#include "Paint.h" 
#include "TetrisGame.h"

const INT BOARD_BOUND = 1 ; 

CTetrisGame::CTetrisGame()
{
    m_nArrSize = DEFAULT_ARRAY_SIZE ; 
    m_eNextId = ID_VOID ;  
    for(INT nY = 0 ; nY <= BLOCK_HEIGHT_COUNT ; nY++)
    {
        m_arrBoard[0][nY] = BOARD_BOUND ; 
        m_arrBoard[11][nY] = BOARD_BOUND ; 
        if(nY < 12)
        {
            m_arrBoard[nY][BLOCK_HEIGHT_COUNT] = BOARD_BOUND ; 
        }
    }
    Create() ; 
}

CTetrisGame::~CTetrisGame()
{

}

void CTetrisGame::Create()
{
    srand((unsigned int)time(NULL)) ;
    BlockId arrBlockId[7] { ID_LICKY, ID_RICKY, ID_CLEVELAND, ID_PHODEISLAND, ID_TEEWEE, ID_SMASHBOY, ID_HERO } ; 
    BlockId eId ;
    if(m_eNextId == ID_VOID)
    {
        eId = arrBlockId[(rand() % 7)] ; 
    }
    else
    {
        eId = m_eNextId ; 
    }
    m_eNextId = arrBlockId[(rand() % 7)] ; 
    switch(eId)
    {
        case ID_LICKY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CLicky>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CLicky>(m_nArrSize) ; 
            break ;
        }
        case ID_RICKY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CRicky>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CRicky>(m_nArrSize) ; 
            break ;
        }
        case ID_CLEVELAND :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CCleveland>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CCleveland>(m_nArrSize) ; 
            break ;
        }
        case ID_PHODEISLAND :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CPhodeisland>(m_nArrSize) ;
            m_spFurBk = std::make_unique<CPhodeisland>(m_nArrSize) ; 
            break ;
        }
        case ID_TEEWEE :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ;
            m_spCurBk = std::make_unique<CTeewee>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CTeewee>(m_nArrSize) ; 
            break ;
        }
        case ID_SMASHBOY :
        {
            m_nArrSize = DEFAULT_ARRAY_SIZE ; 
            m_spCurBk = std::make_unique<CSmashboy>(m_nArrSize) ; 
            m_spFurBk = std::make_unique<CSmashboy>(m_nArrSize) ; 
            break ;
        }
        case ID_HERO :
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
    FutureUpdate() ; 
}

void CTetrisGame::Reach()
{
    INT nX = 0 ;
    INT nY = 0 ;
    INT nLine = 0 ; 
    std::set<INT> setYs ; 
    for(INT nIndex = 0 ; nIndex < m_nArrSize ; nIndex++)
    {
        if(m_spCurBk->GetPos(nIndex, nX, nY))
        {
            m_arrBoard[nX][nY] = m_spCurBk->GetId() ; // mark. 
            setYs.insert(nY) ; 
        }
    }

    if(IsGameOver())
    {
        return ;  
    }

    for(auto it = setYs.begin() ; it != setYs.end() ; it++)
    {
        nLine = *it ; 
        if(IsFull(nLine))
        {
            InUpdate(nLine) ; 
            OutUpdate() ; 
            //CPaint::DrawScores(100) ; 
        }
    }
    Create() ; 
}

bool CTetrisGame::IsFull(INT nLine) 
{
    for(INT nX = 1 ; nX <= BLOCK_WIDTH_COUNT ; nX++)
    {
        if(m_arrBoard[nX][nLine] == BLOCK_ARRAY_SPACE_OFF)
        {
            return false ; 
        }
    }
    return true ; 
}

bool CTetrisGame::IsGameOver() 
{
    for(INT nX = 1 ; nX <= BLOCK_WIDTH_COUNT ; nX++)
    {
        if(m_arrBoard[nX][0] != BLOCK_ARRAY_SPACE_OFF)
        {
            return true ; 
        }
    }
    return false ; 
}

void CTetrisGame::InUpdate(INT nLine)
{   
    for(INT nX = 1 ; nX <= BLOCK_WIDTH_COUNT ; nX++)
    {
        m_arrBoard[nX][nLine] = BLOCK_ARRAY_SPACE_OFF ; // Clear line. 
    }
    for(INT nX = 1 ; nX <= BLOCK_WIDTH_COUNT ; nX++)
    {
        for(INT nY = nLine - 1 ; nY >= 0  ; nY--)
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

void CTetrisGame::FutureUpdate() 
{
    m_spFurBk->Erase() ; 
    *m_spFurBk = *m_spCurBk ; 
    while(IsMoveDown(m_spFurBk.get()))
    {
        m_spFurBk->Down() ; 
    }
    m_spFurBk->FutureDraw() ;
}

void CTetrisGame::Draw()
{
    m_spCurBk->Draw() ;
}

void CTetrisGame::Left()
{
    if(IsMoveLeft())
    {
        m_spCurBk->Left() ; 
        FutureUpdate() ;
    }
}

void CTetrisGame::Right() 
{   
    if(IsMoveRight())
    {
        m_spCurBk->Right() ; 
        FutureUpdate() ;
    }
}

void CTetrisGame::Rotate()
{
    m_spCurBk->Rotate(m_arrBoard) ; 
    FutureUpdate() ;
}

bool CTetrisGame::Down()
{
    if(IsMoveDown(m_spCurBk.get()))
    {
        m_spCurBk->Down() ; 
        m_spCurBk->Draw() ; 
        FutureUpdate() ; 
        return false ; 
    }
    else
    {
        m_spCurBk->Draw() ; 
        Reach() ; 
        return true ;
    }
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